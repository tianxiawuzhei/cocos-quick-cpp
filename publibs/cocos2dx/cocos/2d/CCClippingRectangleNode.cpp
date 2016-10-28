
#include "2d/CCClippingRectangleNode.h"
#include "base/CCDirector.h"
#include "renderer/CCRenderer.h"
#include "math/Vec2.h"
#include "platform/CCGLView.h"

NS_CC_BEGIN

ClippingRectangleNode* ClippingRectangleNode::create(const Rect& clippingRegion)
{
    ClippingRectangleNode* node = new (std::nothrow) ClippingRectangleNode();
    if (node && node->init()) {
        node->setClippingRegion(clippingRegion);
        node->autorelease();
    } else {
        CC_SAFE_DELETE(node);
    }
    
    return node;
}

ClippingRectangleNode* ClippingRectangleNode::create()
{
    ClippingRectangleNode* node = new (std::nothrow) ClippingRectangleNode();
    if (node && node->init()) {
        node->autorelease();
    } else {
        CC_SAFE_DELETE(node);
    }
    
    return node;
}

void ClippingRectangleNode::setClippingRegion(const Rect &clippingRegion)
{
    _clippingRegion = clippingRegion;
}

Rect ClippingRectangleNode::getViewRect()
{
    Vec2 screenPos = this->convertToWorldSpace(Vec2(_clippingRegion.origin.x, _clippingRegion.origin.y));
    
    float scaleX = this->getScaleX();
    float scaleY = this->getScaleY();
    
    for (Node *p = _parent; p != nullptr; p = p->getParent()) {
        scaleX *= p->getScaleX();
        scaleY *= p->getScaleY();
    }
    
    return Rect(screenPos.x, screenPos.y, _clippingRegion.size.width * scaleX,  _clippingRegion.size.height * scaleY);
}


void ClippingRectangleNode::onBeforeVisitScissor()
{
//    if (_clippingEnabled) {
//        glEnable(GL_SCISSOR_TEST);
//
//        float scaleX = _scaleX;
//        float scaleY = _scaleY;
//        Node *parent = this->getParent();
//        while (parent) {
//            scaleX *= parent->getScaleX();
//            scaleY *= parent->getScaleY();
//            parent = parent->getParent();
//        }
//        
//        const Point pos = convertToWorldSpace(Point(_clippingRegion.origin.x, _clippingRegion.origin.y));
//        GLView* glView = Director::getInstance()->getOpenGLView();
//        glView->setScissorInPoints(pos.x,
//                                   pos.y,
//                                   _clippingRegion.size.width * scaleX,
//                                   _clippingRegion.size.height * scaleY);
//    }
    if (_clippingEnabled)
     {
        _scissorRestored = false;
        Rect frame = getViewRect();
        auto glview = Director::getInstance()->getOpenGLView();
        
        if (glview->isScissorEnabled()) {
            _scissorRestored = true;
            _parentScissorRect = glview->getScissorRect();
            //set the intersection of _parentScissorRect and frame as the new scissor rect
            if (frame.intersectsRect(_parentScissorRect)) {
                
                // calculate intersect rect
                float x = MAX(frame.origin.x, _parentScissorRect.origin.x);
                float y = MAX(frame.origin.y, _parentScissorRect.origin.y);
                float xx = MIN(frame.origin.x+frame.size.width, _parentScissorRect.origin.x+_parentScissorRect.size.width);
                float yy = MIN(frame.origin.y+frame.size.height, _parentScissorRect.origin.y+_parentScissorRect.size.height);
                float width = xx -x;
                float height = yy - y;
                
                if (width < 0) {
                    width = 0;
                }
                
                if (height < 0) {
                    height = 0;
                }
                glview->setScissorInPoints(x, y, width, height);
            } else {
                glview->setScissorInPoints(0, 0, 0, 0);
            }
        }
        else {
            glEnable(GL_SCISSOR_TEST);
            glview->setScissorInPoints(frame.origin.x, frame.origin.y, frame.size.width, frame.size.height);
        }
     }

}

void ClippingRectangleNode::onAfterVisitScissor()
{
//    if (_clippingEnabled)
//    {
//        glDisable(GL_SCISSOR_TEST);
//    }
    if (_clippingEnabled)
     {
        if (_scissorRestored) {//restore the parent's scissor rect
            auto glview = Director::getInstance()->getOpenGLView();
            
            glview->setScissorInPoints(_parentScissorRect.origin.x, _parentScissorRect.origin.y, _parentScissorRect.size.width, _parentScissorRect.size.height);
        }
        else {
            glDisable(GL_SCISSOR_TEST);
        }
     }
}

void ClippingRectangleNode::visit(Renderer *renderer, const Mat4 &parentTransform, uint32_t parentFlags)
{
    // quick return if not visible. children won't be drawn.
    if (!_visible)
     {
        return;
     }
    
    uint32_t flags = processParentFlags(parentTransform, parentFlags);
    
    // IMPORTANT:
    // To ease the migration to v3.0, we still support the Mat4 stack,
    // but it is deprecated and your code should not rely on it
    _director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    _director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, _modelViewTransform);
    
    _beforeVisitCmdScissor.init(_globalZOrder);
    _beforeVisitCmdScissor.func = CC_CALLBACK_0(ClippingRectangleNode::onBeforeVisitScissor, this);
    renderer->addCommand(&_beforeVisitCmdScissor);
    
    bool visibleByCamera = isVisitableByVisitingCamera();
    
    int i = 0;
    if(!_children.empty())
     {
        sortAllChildren();
        // draw children zOrder < 0
        for( ; i < _children.size(); i++ )
         {
            auto node = _children.at(i);
            
            if (node && node->getLocalZOrder() < 0)
                node->visit(renderer, _modelViewTransform, flags);
            else
                break;
         }
        // self draw
        if (visibleByCamera)
            this->draw(renderer, _modelViewTransform, flags);
        
        for(auto it=_children.cbegin()+i; it != _children.cend(); ++it)
            (*it)->visit(renderer, _modelViewTransform, flags);
     }
    else if (visibleByCamera)
     {
        this->draw(renderer, _modelViewTransform, flags);
     }
    
    _afterVisitCmdScissor.init(_globalZOrder);
    _afterVisitCmdScissor.func = CC_CALLBACK_0(ClippingRectangleNode::onAfterVisitScissor, this);
    renderer->addCommand(&_afterVisitCmdScissor);
    
    _director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
}



//void ClippingRectangleNode::visit(Renderer *renderer, const Mat4 &parentTransform, uint32_t parentFlags)
//{
//    _beforeVisitCmdScissor.init(_globalZOrder);
//    _beforeVisitCmdScissor.func = CC_CALLBACK_0(ClippingRectangleNode::onBeforeVisitScissor, this);
//    renderer->addCommand(&_beforeVisitCmdScissor);
//    
//    Node::visit(renderer, parentTransform, parentFlags);
//    
//    _afterVisitCmdScissor.init(_globalZOrder);
//    _afterVisitCmdScissor.func = CC_CALLBACK_0(ClippingRectangleNode::onAfterVisitScissor, this);
//    renderer->addCommand(&_afterVisitCmdScissor);
//}

NS_CC_END

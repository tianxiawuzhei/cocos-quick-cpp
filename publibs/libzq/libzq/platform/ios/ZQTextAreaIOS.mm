//
//  ZQTextBoxMac.cpp
//  libzq
//
//  Created by staff on 17/2/13.
//  Copyright © 2017年 zyqiosexercise. All rights reserved.
//

#include "ZQTextAreaIOS.h"
#include "ui/CocosGUI.h"
#include "ui/UIEditBox/iOS/UITextView+CCUITextInput.h"
#include "ui/UIEditBox/iOS/CCUIMultilineTextField.h"

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "platform/ios/CCEAGLView-ios.h"

using namespace zq;

static id current_delegate_ = nil;

@interface ZQTextAreaDelegateIOS : NSObject <UITextViewDelegate>
{
@private
    ZQTextAreaIOS* _host;
}
@end

@implementation ZQTextAreaDelegateIOS

- (instancetype)init
{
    self = [super init];
    
    if (self) {
        
    }
    
    return self;
}

- (void)setHost:(ZQTextAreaIOS *)host
{
    _host = host;
}

- (void)dealloc
{
    if (current_delegate_ == self )
        current_delegate_ = nil;
    [super dealloc];
}

- (BOOL)textViewShouldBeginEditing:(UITextView *)textView
{
    current_delegate_ = self;
    return YES;
}

- (void)textViewDidEndEditing:(UITextView *)textView
{
    if (current_delegate_ == self)
    {
        current_delegate_ = nil;
    }
}

- (void)textViewDidChange:(UITextView *)textView
{
    if (textView.contentSize.height > textView.bounds.size.height)
    {
        CGPoint bottomOffset = CGPointMake(0, textView.contentSize.height - textView.bounds.size.height);
        [textView setContentOffset:bottomOffset animated:NO];
    }
}

- (BOOL)textView:(UITextView *)textView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text
{
    int maxLength = _host->maxLength();
    if (maxLength < 0)
    {
        return YES;
    }
    
    // Prevent crashing undo bug http://stackoverflow.com/questions/433337/set-the-maximum-character-length-of-a-uitextfield
    if (range.length + range.location > textView.text.length) {
        return NO;
    }
    
    NSUInteger oldLength = textView.text.length;
    NSUInteger replacementLength = text.length;
    NSUInteger rangeLength = range.length;
    
    NSUInteger newLength = oldLength - rangeLength + replacementLength;
    
    return newLength <= maxLength;
}

@end

static UIFont* constructFont(const char *fontName, float fontSize, CGRect frame)
{
    NSString * fntName = [NSString stringWithUTF8String:fontName];
    fntName = [[fntName lastPathComponent] stringByDeletingPathExtension];
    float retinaFactor = 1.0f;
    auto glview = cocos2d::Director::getInstance()->getOpenGLView();
    float scaleFactor = glview->getScaleX();
    
    if (fontSize <= 0)
    {
        CGRect frameRect = frame;
        fontSize = frameRect.size.height*2/3;
    }
    else
    {
        fontSize = fontSize * scaleFactor / retinaFactor;
    }
    
    UIFont *textFont = nil;
    if (strlen(fontName) == 0)
    {
        textFont = [UIFont systemFontOfSize:fontSize];
    }
    else
    {
        textFont = [UIFont fontWithName:fntName size:fontSize];
    }
    
    return textFont;
}


ZQTextAreaIOS::ZQTextAreaIOS()
:_font_size(20)
,_view(nullptr)
{
    this->_view = [[CCUIMultilineTextField alloc] init];
    this->_view_delegate = [[ZQTextAreaDelegateIOS alloc]init];
    [(ZQTextAreaDelegateIOS*)this->_view_delegate setHost:this];
    
    [(UITextView*)this->_view setBackgroundColor:[UIColor redColor]];
    [(UITextView*)this->_view ccui_setTextColor:[UIColor whiteColor]];

    [(UITextView*)this->_view setDelegate:(ZQTextAreaDelegateIOS*)this->_view_delegate];
    [(UITextView*)this->_view setTextAlignment:NSTextAlignmentLeft];
    [(UITextView*)this->_view setHidden:NO];
}

ZQTextAreaIOS::~ZQTextAreaIOS()
{
    [(UIView*)this->_view release];
    [(ZQTextAreaDelegateIOS*)this->_view_delegate release];
}

ZQTextAreaIOS* ZQTextAreaIOS::create()
{
    auto view = new ZQTextAreaIOS();
    view->autorelease();
    return view;
}

void ZQTextAreaIOS::setFont(const std::string &font_name, float font_size)
{
    ZQTextArea::setFont(font_name, font_size);
    auto fontSize = font_size*this->getNodeToWorldAffineTransform().a;
    UIFont* font = constructFont(font_name.c_str(), fontSize, [(UIView*)this->_view frame]);
    [(UITextView*)this->_view ccui_setFont:font];
}

void ZQTextAreaIOS::setString(const std::string &text)
{
    [((UITextView*)this->_view) ccui_setText:[NSString stringWithUTF8String:text.c_str()]];
}

void ZQTextAreaIOS::setFontColor(const cocos2d::Color3B &color)
{
    [(UITextView*)this->_view ccui_setTextColor:[UIColor colorWithRed:color.r / 255.0
                                                            green:color.g / 255.0
                                                             blue:color.b / 255.0
                                                            alpha:1.0]];
}

void ZQTextAreaIOS::setPlaceholderFont(const std::string &font_name, float font_size)
{
    ZQTextArea::setPlaceholderFont(font_name, font_size);
}

void ZQTextAreaIOS::setPlaceholderFontColor(const cocos2d::Color4B &color)
{
   
}

void ZQTextAreaIOS::setPlaceHolder(const std::string &text)
{
    [((UITextView*)this->_view) ccui_setPlaceholder:[NSString stringWithUTF8String:text.c_str()]];
}

void ZQTextAreaIOS::setMaxLength(int length)
{
    ZQTextArea::setMaxLength(length);
}

void ZQTextAreaIOS::setAlignmentLeft()
{
    [(UITextView*)this->_view setTextAlignment:NSTextAlignmentLeft];
}

void ZQTextAreaIOS::setAlignmentCenter()
{
    [(UITextView*)this->_view setTextAlignment:NSTextAlignmentCenter];
}

void ZQTextAreaIOS::setAlignmentRight()
{
    [(UITextView*)this->_view setTextAlignment:NSTextAlignmentRight];
}

void ZQTextAreaIOS::focus()
{
    [(UITextView*)this->_view becomeFirstResponder];
}

void ZQTextAreaIOS::update()
{
    if (!this->isRunning())
        return;
    
    auto rect = cocos2d::ui::Helper::convertBoundingBoxToScreen(this);
    cocos2d::GLView* eglView = cocos2d::Director::getInstance()->getOpenGLView();
    CCEAGLView *eaglview = (CCEAGLView*) eglView->getEAGLView();
    
    float factor = eaglview.contentScaleFactor;
    
    [(UITextField*)this->_view setFrame:CGRectMake(rect.origin.x / factor,
                                                   rect.origin.y / factor,
                                                   rect.size.width / factor,
                                                   rect.size.height / factor)];
}

std::string ZQTextAreaIOS::getString()
{
    return [[((UITextView*)this->_view) ccui_text] UTF8String];
}

void ZQTextAreaIOS::openKeyboard()
{
    
}

void ZQTextAreaIOS::setParent(cocos2d::Node *parent)
{
    ZQTextArea::setParent(parent);
    if (parent == nullptr)
    {
        [(UIView*)this->_view removeFromSuperview];
    }
    else
    {
        [(UIView*)cocos2d::Director::getInstance()->getOpenGLView()->getEAGLView() addSubview:(UIView *)this->_view];
        
        this->update();
    }
    
}

void ZQTextAreaIOS::setVisible(bool visible)
{
    ZQTextArea::setVisible(visible);
    [(UIView*)this->_view setHidden:!visible];
}

void ZQTextAreaIOS::setOpacity(GLubyte opacity)
{
    ZQTextArea::setOpacity(opacity);
    [(UIView*)this->_view setAlpha:opacity/255];
}

void ZQTextAreaIOS::keyboardWillShow(cocos2d::IMEKeyboardNotificationInfo& info)
{
    if (current_delegate_ != this->_view_delegate)
    {
        return;
    }
    
    cocos2d::Size contentSize = this->getContentSize();
    cocos2d::Rect rect = cocos2d::Rect(0, 0, contentSize.width, contentSize.height);
    
    cocos2d::Rect rectTracked = RectApplyTransform(rect, this->getNodeToWorldTransform());
    // some adjustment for margin between the keyboard and the edit box.
    rectTracked.origin.y -= 4;
    
    // if the keyboard area doesn't intersect with the tracking node area, nothing needs to be done.
    if (!rectTracked.intersectsRect(info.end))
    {
        CCLOG("needn't to adjust view layout.");
        return;
    }
    
    // assume keyboard at the bottom of screen, calculate the vertical adjustment.
    _adjustHeight = info.end.getMaxY() - rectTracked.getMinY();
    // CCLOG("CCEditBox:needAdjustVerticalPosition(%f)", _adjustHeight);
    
    auto view = cocos2d::Director::getInstance()->getOpenGLView();
    CCEAGLView *eaglview = (CCEAGLView *)view->getEAGLView();
    
    [eaglview doAnimationWhenKeyboardMoveWithDuration:info.duration distance:this->_adjustHeight];
}

void ZQTextAreaIOS::keyboardWillHide(cocos2d::IMEKeyboardNotificationInfo& info)
{
    if (current_delegate_ != this->_view_delegate)
    {
        return;
    }
    
    auto view = cocos2d::Director::getInstance()->getOpenGLView();
    CCEAGLView *eaglview = (CCEAGLView *)view->getEAGLView();
    
    [eaglview doAnimationWhenKeyboardMoveWithDuration:info.duration distance:-this->_adjustHeight];
}


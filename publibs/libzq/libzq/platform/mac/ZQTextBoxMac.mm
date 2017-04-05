//
//  ZQTextBoxMac.cpp
//  libzq
//
//  Created by staff on 17/2/13.
//  Copyright © 2017年 zyqiosexercise. All rights reserved.
//

#include "ZQTextBoxMac.h"
#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>
#include "ui/CocosGUI.h"
#include "ui/UIEditBox/Mac/CCUITextInput.h"
#include "ui/UIEditBox/Mac/CCUISingleLineTextField.h"

using namespace zq;

static id current_delegate_ = nil;

@interface ZQTextBoxDelegateMac : NSObject <NSTextFieldDelegate>
{
@private
    ZQTextBoxMac* _host;
}
@end

@implementation ZQTextBoxDelegateMac

- (instancetype)init
{
    self = [super init];
    
    if (self) {
        
    }
    
    return self;
}

- (void)setHost:(zq::ZQTextBoxMac *)host
{
    _host = host;
}

- (void)dealloc
{
    if (current_delegate_ == self )
        current_delegate_ = nil;
    [super dealloc];
}

- (NSWindow *)window
{
    auto glview = cocos2d::Director::getInstance()->getOpenGLView();
    return glview->getCocoaWindow();
}

- (void)controlTextDidBeginEditing:(NSNotification *)notification
{
    current_delegate_ = self;
}

- (void)controlTextDidEndEditing:(NSNotification *)notification
{
    if (current_delegate_ == self)
    {
        current_delegate_ = nil;
    }
}

/**
 * Called each time when the text field's text has changed.
 */
- (void)controlTextDidChange:(NSNotification *)notification
{
    
}

@end

static NSFont* constructFont(const char *fontName, float fontSize, NSRect frame)
{
    NSString * fntName = [NSString stringWithUTF8String:fontName];
    fntName = [[fntName lastPathComponent] stringByDeletingPathExtension];
    float retinaFactor = 1.0f;
    auto glview = cocos2d::Director::getInstance()->getOpenGLView();
    float scaleFactor = glview->getScaleX();
    
    if (fontSize <= 0)
    {
        NSRect frameRect = frame;
        fontSize = frameRect.size.height*2/3;
    }
    else
    {
        fontSize = fontSize * scaleFactor / retinaFactor;
    }
    
    NSFont *textFont = nil;
    if (strlen(fontName) == 0)
    {
        textFont = [NSFont systemFontOfSize:fontSize];
    }
    else
    {
        textFont = [NSFont fontWithName:fntName size:fontSize];
    }
    
    return textFont;
}


ZQTextBoxMac::ZQTextBoxMac()
:_view(nullptr)
{
    this->_view = [[CCUISingleLineTextField alloc] init];
    this->_view_delegate = [[ZQTextBoxDelegateMac alloc]init];
    [(ZQTextBoxDelegateMac*)this->_view_delegate setHost:this];
    
    [(NSTextField*)this->_view setBackgroundColor:[NSColor clearColor]];
    [(NSTextField*)this->_view setBordered:NO];
    [(CCUISingleLineTextField*)this->_view ccui_setTextColor:[NSColor whiteColor]];

    [(NSTextField*)this->_view setDelegate:(ZQTextBoxDelegateMac*)this->_view_delegate];
    [(NSTextField*)this->_view setAlignment:NSTextAlignmentLeft];
    [(NSTextField*)this->_view setHidden:NO];
    [(NSTextField*)this->_view setWantsLayer:YES];
}

ZQTextBoxMac::~ZQTextBoxMac()
{
    [(NSTextField*)this->_view release];
    [(ZQTextBoxDelegateMac*)this->_view_delegate release];
}

ZQTextBoxMac* ZQTextBoxMac::create()
{
    auto view = new ZQTextBoxMac();
    view->autorelease();
    return view;
}

void ZQTextBoxMac::setFont(const std::string &font_name, float font_size)
{
    ZQTextBox::setFont(font_name, font_size);
    auto fontSize = font_size*this->getNodeToWorldAffineTransform().a;
    NSFont* font = constructFont(font_name.c_str(), fontSize, [(NSTextField*)this->_view frame]);
    [(CCUISingleLineTextField*)this->_view ccui_setFont:font];
}

void ZQTextBoxMac::setString(const std::string &text)
{
    [((CCUISingleLineTextField*)this->_view) ccui_setText:[NSString stringWithUTF8String:text.c_str()]];
}

void ZQTextBoxMac::setFontColor(const cocos2d::Color3B &color)
{
    [(CCUISingleLineTextField*)this->_view ccui_setTextColor:[NSColor colorWithRed:color.r / 255.0
                                                            green:color.g / 255.0
                                                             blue:color.b / 255.0
                                                            alpha:1.0]];
}

void ZQTextBoxMac::setPlaceholderFont(const std::string &font_name, float font_size)
{
    ZQTextBox::setPlaceholderFont(font_name, font_size);
    auto fontSize = font_size*this->getNodeToWorldAffineTransform().a;
    NSFont* font = constructFont(font_name.c_str(), fontSize, [(NSTextField*)this->_view frame]);
    [(CCUISingleLineTextField*)this->_view ccui_setPlaceholderFont:font];
}

void ZQTextBoxMac::setPlaceholderFontColor(const cocos2d::Color4B &color)
{
    [(CCUISingleLineTextField*)this->_view ccui_setPlaceholderColor:[NSColor colorWithRed:color.r / 255.0
                                                                             green:color.g / 255.0
                                                                              blue:color.b / 255.0
                                                                             alpha:color.a]];
}

void ZQTextBoxMac::setPlaceHolder(const std::string &text)
{
    [((CCUISingleLineTextField*)this->_view) ccui_setPlaceholder:[NSString stringWithUTF8String:text.c_str()]];
}

void ZQTextBoxMac::setMaxLength(int length)
{
    ZQTextBox::setMaxLength(length);
    [((CCUISingleLineTextField*)this->_view) ccui_setMaxLength:length];
}

void ZQTextBoxMac::setAlignmentLeft()
{
    [(NSTextField*)this->_view setAlignment:NSTextAlignmentLeft];
}

void ZQTextBoxMac::setAlignmentCenter()
{
    [(NSTextField*)this->_view setAlignment:NSTextAlignmentCenter];
}

void ZQTextBoxMac::setAlignmentRight()
{
    [(NSTextField*)this->_view setAlignment:NSTextAlignmentRight];
}

void ZQTextBoxMac::focus()
{
    [(NSTextField*)this->_view becomeFirstResponder];
}

void ZQTextBoxMac::update()
{
    if (!this->isRunning())
        return;
    
    auto rect = cocos2d::ui::Helper::convertBoundingBoxToScreen(this);
    cocos2d::GLView* eglView = cocos2d::Director::getInstance()->getOpenGLView();
    auto viewPortRect = eglView->getViewPortRect();
    // Coordinate System on OSX has its origin at the lower left corner.
    //    https://developer.apple.com/library/ios/documentation/General/Conceptual/Devpedia-CocoaApp/CoordinateSystem.html
    auto screenPosY = viewPortRect.size.height - rect.origin.y - rect.size.height;
    [(NSTextField*)this->_view setFrame:CGRectMake(rect.origin.x,
                                     screenPosY,
                                     rect.size.width, rect.size.height)];
}

std::string ZQTextBoxMac::getString()
{
    return [[((CCUISingleLineTextField*)this->_view) ccui_text] UTF8String];
}

void ZQTextBoxMac::openKeyboard()
{
    
}

void ZQTextBoxMac::setParent(cocos2d::Node *parent)
{
    cocos2d::Node::setParent(parent);
    if (parent == nullptr)
    {
        [(NSTextField*)this->_view removeFromSuperview];
    }
    else
    {
        auto glview = cocos2d::Director::getInstance()->getOpenGLView();
        NSWindow* window = glview->getCocoaWindow();
        [window.contentView addSubview:(NSTextField*)this->_view];
        this->update();
    }
    
}

void ZQTextBoxMac::setVisible(bool visible)
{
    ZQTextBox::setVisible(visible);
    [(NSTextField*)this->_view setHidden:!visible];
}

void ZQTextBoxMac::setOpacity(GLubyte opacity)
{
    ZQTextBox::setOpacity(opacity);
    [(NSTextField*)this->_view setAlphaValue:opacity/255];
}

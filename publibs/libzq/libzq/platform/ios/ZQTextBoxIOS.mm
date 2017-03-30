//
//  ZQTextBoxMac.cpp
//  libzq
//
//  Created by staff on 17/2/13.
//  Copyright © 2017年 zyqiosexercise. All rights reserved.
//

#include "ZQTextBoxIOS.h"
#include "ui/CocosGUI.h"
#include "ui/UIEditBox/iOS/CCUITextInput.h"
#include "ui/UIEditBox/iOS/CCUISingleLineTextField.h"

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ui/UIEditBox/iOS/CCUITextInput.h"
#import "ui/UIEditBox/iOS/UITextView+CCUITextInput.h"

using namespace zq;

static id current_delegate_ = nil;

@interface ZQTextBoxDelegateIOS : NSObject <UITextFieldDelegate>
{
@private
    ZQTextBoxIOS* _host;
}
@end

@implementation ZQTextBoxDelegateIOS

- (instancetype)init
{
    self = [super init];
    
    if (self) {
        
    }
    
    return self;
}

- (void)setHost:(ZQTextBoxIOS *)host
{
    _host = host;
}

- (void)dealloc
{
    if (current_delegate_ == self )
        current_delegate_ = nil;
    [super dealloc];
}

- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField
{
    current_delegate_ = self;
    return YES;
}

-(BOOL) textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    return YES;
}

- (void)textFieldDidEndEditing:(UITextField *)textField
{
    if (current_delegate_ == self)
    {
        current_delegate_ = nil;
    }
}

/**
 * Called each time when the text field's text has changed.
 */
- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string
{
    if (!_host->maxLength())
        return YES;
    
    NSUInteger oldLength = [textField.text length];
    NSUInteger replacementLength = [string length];
    NSUInteger rangeLength = range.length;
    
    NSUInteger newLength = oldLength - rangeLength + replacementLength;
    
    BOOL returnKey = [string rangeOfString: @"\n"].location != NSNotFound;
    
    return (newLength <= _host->maxLength()) || returnKey;
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


ZQTextBoxIOS::ZQTextBoxIOS()
:_view(nullptr)
{
    this->_view = [[UITextField alloc] init];
    this->_view_delegate = [[ZQTextBoxDelegateIOS alloc]init];
    [(ZQTextBoxDelegateIOS*)this->_view_delegate setHost:this];
    
    [(UITextField*)this->_view setBackgroundColor:[UIColor clearColor]];
    [(UITextField*)this->_view ccui_setTextColor:[UIColor whiteColor]];

    [(UITextField*)this->_view setDelegate:(ZQTextBoxDelegateIOS*)this->_view_delegate];
    [(UITextField*)this->_view setAlignment:NSTextAlignmentLeft];
    [(UITextField*)this->_view setHidden:NO];
}

ZQTextBoxIOS::~ZQTextBoxIOS()
{
    [(UIView*)this->_view release];
    [(ZQTextBoxDelegateIOS*)this->_view_delegate release];
}

ZQTextBoxIOS* ZQTextBoxIOS::create()
{
    auto view = new ZQTextBoxIOS();
    view->autorelease();
    return view;
}

void ZQTextBoxIOS::setFont(const std::string &font_name, float font_size)
{
    ZQTextBox::setFont(font_name, font_size);
    auto fontSize = font_size*this->getNodeToWorldAffineTransform().a;
    UIFont* font = constructFont(font_name.c_str(), fontSize, [(UITextField*)this->_view frame]);
    [(UITextField*)this->_view ccui_setFont:font];
}

void ZQTextBoxIOS::setString(const std::string &text)
{
    [((UITextField*)this->_view) ccui_setText:[NSString stringWithUTF8String:text.c_str()]];
}

void ZQTextBoxIOS::setFontColor(const cocos2d::Color3B &color)
{
    [(UITextField*)this->_view ccui_setTextColor:[UIColor colorWithRed:color.r / 255.0
                                                            green:color.g / 255.0
                                                             blue:color.b / 255.0
                                                            alpha:1.0]];
}

void ZQTextBoxIOS::setPlaceholderFont(const std::string &font_name, float font_size)
{
//    ZQTextBox::setPlaceholderFont(font_name, font_size);
//    auto fontSize = font_size*this->getNodeToWorldAffineTransform().a;
//    UIFont* font = constructFont(font_name.c_str(), fontSize, [(UIView*)this->_view frame]);
//    [(UITextField*)this->_view ccui_setPlaceholderFont:font];
}

void ZQTextBoxIOS::setPlaceholderFontColor(const cocos2d::Color4B &color)
{
//    [(UITextField*)this->_view ccui_set:[UIColor colorWithRed:color.r / 255.0
//                                                                             green:color.g / 255.0
//                                                                              blue:color.b / 255.0
//                                                                             alpha:color.a]];
}

void ZQTextBoxIOS::setPlaceHolder(const std::string &text)
{
    [((UITextField*)this->_view) ccui_setPlaceholder:[NSString stringWithUTF8String:text.c_str()]];
}

void ZQTextBoxIOS::setMaxLength(int length)
{
    ZQTextBox::setMaxLength(length);
//    [((UITextField*)this->_view) ccui_setMaxLength:length];
}

void ZQTextBoxIOS::setAlignmentLeft()
{
    [(UITextField*)this->_view setAlignment:NSTextAlignmentLeft];
}

void ZQTextBoxIOS::setAlignmentCenter()
{
    [(UITextField*)this->_view setAlignment:NSTextAlignmentCenter];
}

void ZQTextBoxIOS::setAlignmentRight()
{
    [(UITextField*)this->_view setAlignment:NSTextAlignmentRight];
}

void ZQTextBoxIOS::focus()
{
    [(UITextField*)this->_view becomeFirstResponder];
}

void ZQTextBoxIOS::update()
{
    auto rect = cocos2d::ui::Helper::convertBoundingBoxToScreen(this);
    cocos2d::GLView* eglView = cocos2d::Director::getInstance()->getOpenGLView();
    auto viewPortRect = eglView->getViewPortRect();
    // Coordinate System on OSX has its origin at the lower left corner.
    //    https://developer.apple.com/library/ios/documentation/General/Conceptual/Devpedia-CocoaApp/CoordinateSystem.html
    auto screenPosY = viewPortRect.size.height - rect.origin.y - rect.size.height;
    [(UITextField*)this->_view setFrame:CGRectMake(rect.origin.x,
                                     screenPosY,
                                     rect.size.width, rect.size.height)];
}

std::string ZQTextBoxIOS::getString()
{
    return [[((UITextField*)this->_view) ccui_text] UTF8String];
}

void ZQTextBoxIOS::openKeyboard()
{
    
}

void ZQTextBoxIOS::setParent(cocos2d::Node *parent)
{
    cocos2d::Node::setParent(parent);
    if (parent == nullptr)
    {
        [(UITextField*)this->_view removeFromSuperview];
    }
    else
    {
        [(UIView*)cocos2d::Director::getInstance()->getOpenGLView()->getEAGLView() addSubview:(UIView*)this->_view];
        this->update();
    }
    
}

void ZQTextBoxIOS::setVisible(bool visible)
{
    ZQTextBox::setVisible(visible);
    [(UITextField*)this->_view setHidden:!visible];
}

void ZQTextBoxIOS::setOpacity(GLubyte opacity)
{
    ZQTextBox::setOpacity(opacity);
    [(UITextField*)this->_view setAlpha:opacity/255];
}

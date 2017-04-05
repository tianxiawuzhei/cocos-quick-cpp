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
#import "platform/ios/CCEAGLView-ios.h"

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
,_adjustHeight(0.0)
{
    this->_view = [[UITextField alloc] init];
    this->_view_delegate = [[ZQTextBoxDelegateIOS alloc]init];
    [(ZQTextBoxDelegateIOS*)this->_view_delegate setHost:this];
    
    [(UITextField*)this->_view setBackgroundColor:[UIColor clearColor]];
    [(UITextField*)this->_view ccui_setTextColor:[UIColor whiteColor]];
    [(UITextField*)this->_view setReturnKeyType:UIReturnKeyDone];
    [(UITextField*)this->_view setContentVerticalAlignment:UIControlContentVerticalAlignmentCenter];
    
    [(UITextField*)this->_view setDelegate:(ZQTextBoxDelegateIOS*)this->_view_delegate];
    [(UITextField*)this->_view setTextAlignment:NSTextAlignmentLeft];
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

void ZQTextBoxIOS::setKeyboardDefault()
{
    [((UITextField*)this->_view) setKeyboardType:UIKeyboardTypeDefault];
}

void ZQTextBoxIOS::setKeyboardURL()
{
    [((UITextField*)this->_view) setKeyboardType:UIKeyboardTypeURL];
}

void ZQTextBoxIOS::setKeyboardNumber()
{
    [(UITextField*)this->_view setKeyboardType:UIKeyboardTypeDecimalPad];
}

void ZQTextBoxIOS::setKeyboardEmail()
{
    [(UITextField*)this->_view setKeyboardType:UIKeyboardTypeEmailAddress];
}

void ZQTextBoxIOS::setAlignmentLeft()
{
    [(UITextField*)this->_view setTextAlignment:NSTextAlignmentLeft];
}

void ZQTextBoxIOS::setAlignmentCenter()
{
    [(UITextField*)this->_view setTextAlignment:NSTextAlignmentCenter];
}

void ZQTextBoxIOS::setAlignmentRight()
{
    [(UITextField*)this->_view setTextAlignment:NSTextAlignmentRight];
}

void ZQTextBoxIOS::focus()
{
    [(UITextField*)this->_view becomeFirstResponder];
}

void ZQTextBoxIOS::update()
{
    auto rect = cocos2d::ui::Helper::convertBoundingBoxToScreen(this);
    cocos2d::GLView* eglView = cocos2d::Director::getInstance()->getOpenGLView();
    CCEAGLView *eaglview = (CCEAGLView*) eglView->getEAGLView();
    
    float factor = eaglview.contentScaleFactor;
    
    [(UITextField*)this->_view setFrame:CGRectMake(rect.origin.x / factor,
                                                   rect.origin.y / factor,
                                                   rect.size.width / factor,
                                                   rect.size.height / factor)];
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

void ZQTextBoxIOS::keyboardWillShow(cocos2d::IMEKeyboardNotificationInfo& info)
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

void ZQTextBoxIOS::keyboardWillHide(cocos2d::IMEKeyboardNotificationInfo& info)
{
    if (current_delegate_ != this->_view_delegate)
    {
        return;
    }
    
    auto view = cocos2d::Director::getInstance()->getOpenGLView();
    CCEAGLView *eaglview = (CCEAGLView *)view->getEAGLView();
    
    [eaglview doAnimationWhenKeyboardMoveWithDuration:info.duration distance:-this->_adjustHeight];
}


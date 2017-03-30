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
    
    [(UITextView*)this->_view setBackgroundColor:[UIColor clearColor]];
    [(UITextView*)this->_view ccui_setTextColor:[UIColor whiteColor]];

    [(UITextView*)this->_view setDelegate:(ZQTextAreaDelegateIOS*)this->_view_delegate];
    [(UITextView*)this->_view setAlignment:NSTextAlignmentLeft];
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

void ZQTextAreaIOS::setFontSize(float font_size)
{
    this->_font_size = font_size;
    this->update();
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
    auto fontSize = font_size*this->getNodeToWorldAffineTransform().a;
    UIFont* font = constructFont(font_name.c_str(), fontSize, [(UIView*)this->_view frame]);
    [(UITextView*)this->_view ccui_setPlaceholderFont:font];
}

void ZQTextAreaIOS::setPlaceholderFontColor(const cocos2d::Color4B &color)
{
    [(UITextView*)this->_view ccui_setPlaceholderColor:[UIColor colorWithRed:color.r / 255.0
                                                                             green:color.g / 255.0
                                                                              blue:color.b / 255.0
                                                                             alpha:color.a]];
}

void ZQTextAreaIOS::setPlaceHolder(const std::string &text)
{
    [((UITextView*)this->_view) ccui_setPlaceholder:[NSString stringWithUTF8String:text.c_str()]];
}

void ZQTextAreaIOS::setMaxLength(int length)
{
    ZQTextArea::setMaxLength(length);
    [((UITextView*)this->_view) ccui_setMaxLength:length];
}

void ZQTextAreaIOS::setAlignmentLeft()
{
    [(UITextView*)this->_view setAlignment:NSTextAlignmentLeft];
}

void ZQTextAreaIOS::setAlignmentCenter()
{
    [(UITextView*)this->_view setAlignment:NSTextAlignmentCenter];
}

void ZQTextAreaIOS::setAlignmentRight()
{
    [(UITextView*)this->_view setAlignment:NSTextAlignmentRight];
}

void ZQTextAreaIOS::focus()
{
    [(UITextView*)this->_view becomeFirstResponder];
}

void ZQTextAreaIOS::update()
{
    auto rect = cocos2d::ui::Helper::convertBoundingBoxToScreen(this);
    cocos2d::GLView* eglView = cocos2d::Director::getInstance()->getOpenGLView();
    auto viewPortRect = eglView->getViewPortRect();
    // Coordinate System on OSX has its origin at the lower left corner.
    //    https://developer.apple.com/library/ios/documentation/General/Conceptual/Devpedia-CocoaApp/CoordinateSystem.html
    auto screenPosY = viewPortRect.size.height - rect.origin.y - rect.size.height;
    [(UIView*)this->_view setFrame:CGRectMake(rect.origin.x,
                                                  screenPosY,
                                                  rect.size.width, rect.size.height)];
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

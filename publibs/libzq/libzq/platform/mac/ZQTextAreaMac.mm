//
//  ZQTextBoxMac.cpp
//  libzq
//
//  Created by staff on 17/2/13.
//  Copyright © 2017年 zyqiosexercise. All rights reserved.
//

#include "ZQTextAreaMac.h"
#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>
#include "ui/CocosGUI.h"
#include "ui/UIEditBox/Mac/CCUITextInput.h"
#include "ui/UIEditBox/Mac/CCUIMultilineTextField.h"

using namespace zq;

static id current_delegate_ = nil;

@interface ZQTextAreaDelegateMac : NSObject <NSTextViewDelegate>
{
@private
    ZQTextAreaMac* _host;
}
@end

@implementation ZQTextAreaDelegateMac

- (instancetype)init
{
    self = [super init];
    
    if (self) {
        
    }
    
    return self;
}

- (void)setHost:(zq::ZQTextAreaMac *)host
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

- (BOOL)textShouldBeginEditing:(NSText *)textObject;        // YES means do it
{
    current_delegate_ = self;
    return YES;
}

- (void)textDidEndEditing:(NSNotification *)notification
{
    if (current_delegate_ == self)
    {
        current_delegate_ = nil;
    }
}

- (void)textDidChange:(NSNotification *)notification
{
     [(NSTextView*)notification.object scrollRangeToVisible: NSMakeRange(((NSTextView*)notification.object).string.length, 0)];
}

- (BOOL)textView:(NSTextView *)textView shouldChangeTextInRange:(NSRange)affectedCharRange replacementString:(NSString *)replacementString
{
    int maxLength = _host->maxLength();
    if (maxLength < 0)
    {
        return YES;
    }
    
    if (affectedCharRange.length + affectedCharRange.location > textView.string.length) {
        return NO;
    }
    
    NSUInteger oldLength = textView.string.length;
    NSUInteger replacementLength = replacementString.length;
    NSUInteger rangeLength = affectedCharRange.length;
    
    NSUInteger newLength = oldLength - rangeLength + replacementLength;
    
    return newLength <= maxLength;
}

@end

static NSFont* constructFont(const char *fontName, float fontSize, NSRect frame)
{
    NSString * fntName = [NSString stringWithUTF8String:fontName];
    fntName = [[fntName lastPathComponent] stringByDeletingPathExtension];
    float retinaFactor = 1.0f;
    auto glview = cocos2d::Director::getInstance()->getOpenGLView();
    float scaleFactor = glview->getScaleX();
    
    if (fontSize == -1)
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


ZQTextAreaMac::ZQTextAreaMac()
:_font_size(20)
,_view(nullptr)
{
    this->_scrollView = [[NSScrollView alloc]init];
    [(NSScrollView*)this->_scrollView setBorderType:NSNoBorder];
    [(NSScrollView*)this->_scrollView setHasVerticalScroller:NO];
    [(NSScrollView*)this->_scrollView setHasHorizontalScroller:NO];
    
    this->_view = [[CCUIMultilineTextField alloc] init];
    this->_view_delegate = [[ZQTextAreaDelegateMac alloc]init];
    [(ZQTextAreaDelegateMac*)this->_view_delegate setHost:this];
    
    [(NSTextView*)this->_view setBackgroundColor:[NSColor clearColor]];
    [(CCUIMultilineTextField*)this->_view ccui_setTextColor:[NSColor whiteColor]];

    [(NSTextView*)this->_view setDelegate:(ZQTextAreaDelegateMac*)this->_view_delegate];
    [(NSTextView*)this->_view setAlignment:NSTextAlignmentLeft];
    [(NSTextView*)this->_view setHidden:NO];
    [(NSTextView*)this->_view setVerticallyResizable:YES];
    [(NSTextView*)this->_view setWantsLayer:YES];
}

ZQTextAreaMac::~ZQTextAreaMac()
{
    [(NSView*)this->_scrollView release];
    [(NSView*)this->_view release];
    [(ZQTextAreaDelegateMac*)this->_view_delegate release];
}

ZQTextAreaMac* ZQTextAreaMac::create()
{
    auto view = new ZQTextAreaMac();
    view->autorelease();
    return view;
}

void ZQTextAreaMac::setFont(const std::string &font_name, float font_size)
{
    ZQTextArea::setFont(font_name, font_size);
    auto fontSize = font_size*this->getNodeToWorldAffineTransform().a;
    NSFont* font = constructFont(font_name.c_str(), fontSize, [(NSTextField*)this->_view frame]);
    [(CCUIMultilineTextField*)this->_view ccui_setFont:font];
}

void ZQTextAreaMac::setString(const std::string &text)
{
    [((CCUIMultilineTextField*)this->_view) ccui_setText:[NSString stringWithUTF8String:text.c_str()]];
}

void ZQTextAreaMac::setFontSize(float font_size)
{
    this->_font_size = font_size;
    this->update();
}

void ZQTextAreaMac::setFontColor(const cocos2d::Color3B &color)
{
    [(CCUIMultilineTextField*)this->_view ccui_setTextColor:[NSColor colorWithRed:color.r / 255.0
                                                            green:color.g / 255.0
                                                             blue:color.b / 255.0
                                                            alpha:1.0]];
}

void ZQTextAreaMac::setPlaceholderFont(const std::string &font_name, float font_size)
{
    ZQTextArea::setPlaceholderFont(font_name, font_size);
    auto fontSize = font_size*this->getNodeToWorldAffineTransform().a;
    NSFont* font = constructFont(font_name.c_str(), fontSize, [(NSTextField*)this->_view frame]);
    [(CCUIMultilineTextField*)this->_view ccui_setPlaceholderFont:font];
}

void ZQTextAreaMac::setPlaceholderFontColor(const cocos2d::Color4B &color)
{
    [(CCUIMultilineTextField*)this->_view ccui_setPlaceholderColor:[NSColor colorWithRed:color.r / 255.0
                                                                             green:color.g / 255.0
                                                                              blue:color.b / 255.0
                                                                             alpha:color.a]];
}

void ZQTextAreaMac::setPlaceHolder(const std::string &text)
{
    [((CCUIMultilineTextField*)this->_view) ccui_setPlaceholder:[NSString stringWithUTF8String:text.c_str()]];
}

void ZQTextAreaMac::setMaxLength(int length)
{
    ZQTextArea::setMaxLength(length);
    [((CCUIMultilineTextField*)this->_view) ccui_setMaxLength:length];
}

void ZQTextAreaMac::setAlignmentLeft()
{
    [(NSTextView*)this->_view setAlignment:NSTextAlignmentLeft];
}

void ZQTextAreaMac::setAlignmentCenter()
{
    [(NSTextView*)this->_view setAlignment:NSTextAlignmentCenter];
}

void ZQTextAreaMac::setAlignmentRight()
{
    [(NSTextView*)this->_view setAlignment:NSTextAlignmentRight];
}

void ZQTextAreaMac::focus()
{
    [(NSTextView*)this->_view becomeFirstResponder];
}

void ZQTextAreaMac::update()
{
    if (!this->isRunning())
        return;
    
    auto rect = cocos2d::ui::Helper::convertBoundingBoxToScreen(this);
    cocos2d::GLView* eglView = cocos2d::Director::getInstance()->getOpenGLView();
    auto viewPortRect = eglView->getViewPortRect();
    // Coordinate System on OSX has its origin at the lower left corner.
    //    https://developer.apple.com/library/ios/documentation/General/Conceptual/Devpedia-CocoaApp/CoordinateSystem.html
    auto screenPosY = viewPortRect.size.height - rect.origin.y - rect.size.height;
//    [(NSTextView*)this->_view setFrame:CGRectMake(rect.origin.x,
//                                     screenPosY,
//                                     rect.size.width, rect.size.height)];
    [(NSView*)this->_scrollView setFrame:CGRectMake(rect.origin.x,
                                                  screenPosY,
                                                  rect.size.width, rect.size.height)];
    [(NSView*)this->_view setFrame:[(NSView*)this->_scrollView bounds]];

}

std::string ZQTextAreaMac::getString()
{
    return [[((CCUIMultilineTextField*)this->_view) ccui_text] UTF8String];
}

void ZQTextAreaMac::openKeyboard()
{
    
}

void ZQTextAreaMac::setParent(cocos2d::Node *parent)
{
    ZQTextArea::setParent(parent);
    if (parent == nullptr)
    {
        [(NSView*)this->_scrollView removeFromSuperview];
    }
    else
    {
        auto glview = cocos2d::Director::getInstance()->getOpenGLView();
        NSWindow* window = glview->getCocoaWindow();
        [window.contentView addSubview:(NSView*)this->_scrollView];
        [(NSScrollView*)this->_scrollView setDocumentView:(NSView*)this->_view];
        this->update();
    }
    
}

void ZQTextAreaMac::setVisible(bool visible)
{
    ZQTextArea::setVisible(visible);
    [(NSView*)this->_view setHidden:!visible];
}

void ZQTextAreaMac::setOpacity(GLubyte opacity)
{
    ZQTextArea::setOpacity(opacity);
    [(NSView*)this->_view setAlphaValue:opacity/255];
}

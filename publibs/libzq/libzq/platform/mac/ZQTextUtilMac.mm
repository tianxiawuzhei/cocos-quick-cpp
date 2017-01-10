/***********************************************
* ZQTextUtilMac.cpp
*
* @author: zyq
* @date: 17/1/5
* @Description:
*
***********************************************/

#include "ZQTextUtilMac.h"
#import <Cocoa/Cocoa.h>

using namespace zq;

ZQTextUtilMac* ZQTextUtilMac::getInstance()
{
    static ZQTextUtilMac instance;
    return &instance;
}

std::string ZQTextUtilMac::standardFontName()
{
    return [[[NSFont boldSystemFontOfSize:23] fontName] UTF8String];
}

cocos2d::Size ZQTextUtilMac::sizeByFont(const std::string &text, const std::string &font_name, float font_size)
{
    NSString * str  = [NSString stringWithUTF8String:text.c_str()];
    NSSize textRect = NSZeroSize;
    textRect.width  = 0x7fffffff;
    textRect.height = 0x7fffffff;
    
    NSFont *font = [NSFont fontWithName:[NSString stringWithUTF8String:font_name.c_str()] size:font_size];
    
    NSSize size;
    NSDictionary *attibutes = @{NSFontAttributeName:font};
#ifdef __MAC_10_11
#if __MAC_OS_X_VERSION_MAX_ALLOWED >= __MAC_10_11
    size = [str boundingRectWithSize:textRect options:(NSStringDrawingOptions)(NSStringDrawingUsesLineFragmentOrigin) attributes:attibutes context:nil].size;
#else
    size = [str boundingRectWithSize:textRect options:(NSStringDrawingOptions)(NSStringDrawingUsesLineFragmentOrigin) attributes:attibutes].size;
#endif
#else
    size = [str boundingRectWithSize:textRect options:(NSStringDrawingOptions)(NSStringDrawingUsesLineFragmentOrigin) attributes:attibutes].size;
#endif
    
    return cocos2d::Size(size.width, size.height);
}

bool ZQTextUtilMac::renderByArray(cocos2d::Sprite *sprite, const cocos2d::ValueVector &lines, int width, int height)
{
    // 检查
    if (lines.empty() || !width || !height)
        return false;
    
    // OpenGL对纹理大小有限制
    // 不同机器不一样，iphone4应该是2048*2048
    GLint limit = 0;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &limit);
    
    if ((width > limit) || (height > limit))
    {
        //PILogE("text util texture too big: %d, %d, max: %d", width, height, limit);
        return false;
    }
    
    // 创建context，申请内存空间
    CGColorSpaceRef colorspace = CGColorSpaceCreateDeviceRGB();
    int              FinalWide = width;
    int              FinalHigh = height;
    
    unsigned int length = FinalWide * FinalHigh * 4;
    unsigned char *data = (unsigned char *)malloc(length);
    memset(data, 0, length);
    
    // 使用RGBA，premulti模式
    CGContextRef context = CGBitmapContextCreate(data, FinalWide, FinalHigh, 8, 4 * FinalWide, colorspace, kCGImageAlphaPremultipliedLast);
    
    if (!context)
    {
        delete [] data;
        CGColorSpaceRelease(colorspace);
        return false;
    }
    
    [NSGraphicsContext setCurrentContext:[NSGraphicsContext graphicsContextWithCGContext:context flipped:true]];
    // 翻转坐标系统（文本原来是倒的要翻转下）
    CGContextSetTextMatrix(context, CGAffineTransformIdentity);
    CGContextTranslateCTM(context, 0, FinalHigh);
    CGContextScaleCTM(context, 1.0, -1.0);
//
    // 抗锯齿
    CGContextSetShouldAntialias(context, true);
    CGContextSetAllowsAntialiasing(context, true);
    
    // 渲染文本
    for (auto i = 0; i < lines.size(); ++i)
    {
        auto line  = lines[i].asValueMap();
        auto units = line["_units"].asValueVector();
        
        for (auto j = 0; j < units.size(); ++j)
        {
            auto unit = units[j].asValueMap();
            if (!unit["_visible"].asBool())
                continue;
            
            auto text     = unit["_text"].asString();
            auto font     = unit["_font"].asString();
            auto color    = unit["_color"].asValueMap();
            auto stroke   = unit["_stroke_color"].asValueMap();
            auto stroke_w = unit["_stroke_width"].asFloat();
            
            auto size  = unit["_size"].asDouble();
            auto under = unit["_underline"].asBool();
            auto x     = unit["_x"].asDouble();
            auto y     = unit["_y"].asDouble();
            auto w     = unit["_w"].asDouble();
            auto h     = unit["_h"].asDouble();
            
            cocos2d::Color3B clr_fore(color["r"].asDouble(), color["g"].asDouble(), color["b"].asDouble());
            cocos2d::Color4B clr_stroke(stroke["r"].asDouble(), stroke["g"].asDouble(), stroke["b"].asDouble(), stroke["a"].asDouble());
            
            // color
            NSColor* foregroundColor;
            foregroundColor = [NSColor colorWithDeviceRed:clr_fore.r/255.0 green:clr_fore.g/255.0 blue:clr_fore.b/255.0 alpha:1.0];
            
            NSFont *ft = [NSFont fontWithName:[NSString stringWithUTF8String:font.c_str()] size:size];
            NSString *str = [NSString stringWithUTF8String:text.c_str()];
            
            NSColor* strokeColor = [NSColor colorWithDeviceRed:clr_stroke.r/255.0 green:clr_stroke.g/255.0 blue:clr_stroke.b/255.0 alpha:1.0];
            
            
            // attribute
            NSDictionary* attriDict = [NSDictionary dictionaryWithObjectsAndKeys:
                                                 foregroundColor,NSForegroundColorAttributeName,
                                                 ft, NSFontAttributeName,
                                                 nil];
            
            if (stroke_w > 0) {
                [attriDict setValue:strokeColor forKey:NSStrokeColorAttributeName];
                [attriDict setValue:[NSNumber numberWithFloat:stroke_w]  forKey:NSStrokeWidthAttributeName];
            }
            
            NSAttributedString *stringWithAttributes =[[[NSAttributedString alloc] initWithString:str
                                                                                       attributes:attriDict] autorelease];
            
            
//            if (stroke_w > 0)
//            {
//                CGContextSetLineWidth(context, stroke_w);
//                CGContextSetLineJoin(context, kCGLineJoinRound);
//                CGContextSetRGBFillColor(context, clr_stroke.r / 255.0, clr_stroke.g / 255.0, clr_stroke.b / 255.0, clr_stroke.a / 255.0);
//                CGContextSetRGBStrokeColor(context, clr_stroke.r / 255.0, clr_stroke.g / 255.0, clr_stroke.b / 255.0, clr_stroke.a / 255.0);
//                CGContextSetTextDrawingMode(context, kCGTextStroke);
//                
//                [str drawAtPoint:CGPointMake(x, y + 1) withFont:ft];
//            }
            
            // 填充
//            CGContextSetTextDrawingMode(context, kCGTextFill);
//            CGContextSetRGBFillColor(context, clr_fore.r / 255.0, clr_fore.g / 255.0, clr_fore.b / 255.0, 1.0);
//            [str drawAtPoint:CGPointMake(x, y) withFont:ft];
//            CTLineRef line = CTLineCreateWithAttributedString((CFAttributedStringRef)stringWithAttributes);
            CGPoint pos = CGPointMake(x, y);
//            CGContextSetTextPosition(context, x, y);
//            CTLineDraw(line, context);
//            CFRelease(line);
            [stringWithAttributes drawAtPoint: pos];
            // 下划线
            if (under)
            {
                CGContextBeginPath(context);
                CGContextSetRGBStrokeColor(context, clr_fore.r / 255.0, clr_fore.g / 255.0, clr_fore.b / 255.0, 1.0);
                CGContextSetLineWidth(context, 1.3);
                CGContextMoveToPoint(context, x, y + h - 1.0);
                CGContextAddLineToPoint(context, x + w, y + h - 1.0);
                CGContextStrokePath(context);
            }
        }
    }
    
    // 创建纹理
    auto texture = new cocos2d::Texture2D;
    texture->initWithData(data, length, cocos2d::Texture2D::PixelFormat::RGBA8888, FinalWide, FinalHigh, cocos2d::Size(width, height));
    texture->setPremultipliedAlpha(true);
    sprite->setTexture(texture);
    
    // 清理
    texture->release();
    delete [] data;
    
    CGColorSpaceRelease(colorspace);
    CGContextRelease(context);
    
    return true;
}

bool ZQTextUtilMac::renderByString(cocos2d::Sprite *sprite, const std::string &info, int width, int height)
{
    return true;
}

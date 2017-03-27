/***********************************************
* ZQTextUtilIOS.cpp
*
* @author: zyq
* @date: 17/3/27
* @Description:
*
***********************************************/

#include "ZQTextUtilIOS.h"
#import <UIKit/UIKit.h>

using namespace zq;

ZQTextUtilIOS* ZQTextUtilIOS::getInstance()
{
    static ZQTextUtilIOS instance;
    return &instance;
}

std::string ZQTextUtilIOS::standardFontName()
{
    return [[[UIFont boldSystemFontOfSize:23.0] fontName] UTF8String];
}

cocos2d::Size ZQTextUtilIOS::sizeByFont(const std::string &text, const std::string &font_name, float font_size)
{
    NSString *str = [NSString stringWithUTF8String:text.c_str()];
    CGSize size = [str sizeWithFont:[UIFont fontWithName:[NSString stringWithUTF8String:font_name.c_str()] size:font_size]];
    return cocos2d::Size(size.width, size.height);
}

bool ZQTextUtilIOS::renderByArray(cocos2d::Sprite *sprite, const cocos2d::ValueVector &lines, int width, int height)
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
//        PILogE("text util texture too big: %d, %d, max: %d", width, height, limit);
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
    
    // 翻转坐标系统（文本原来是倒的要翻转下）
    CGContextSetTextMatrix(context, CGAffineTransformIdentity);
    CGContextTranslateCTM(context, 0, FinalHigh);
    CGContextScaleCTM(context, 1.0, -1.0);
    
    // push
    UIGraphicsPushContext(context);
    
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
            auto stroke   = unit["_stroke"].asValueMap();
            auto stroke_w = unit["_stroke_width"].asFloat();
            
            auto size  = unit["_size"].asDouble();
            auto under = unit["_underline"].asBool();
            auto x     = unit["_x"].asDouble();
            auto y     = unit["_y"].asDouble();
            auto w     = unit["_w"].asDouble();
            auto h     = unit["_h"].asDouble();
            
            cocos2d::Color3B clr_fore(color["r"].asDouble(), color["g"].asDouble(), color["b"].asDouble());
            cocos2d::Color4B clr_stroke(stroke["r"].asDouble(), stroke["g"].asDouble(), stroke["b"].asDouble(), stroke["a"].asDouble());
            
            // 描边
            // ios 7.1有bug，设置stroke color无效，只能把fill color当stroke color用
            NSString *str = [NSString stringWithUTF8String:text.c_str()];
            UIFont   *ft  = [UIFont fontWithName:[NSString stringWithUTF8String:font.c_str()] size:size];
            
            if (stroke_w > 0)
            {
                CGContextSetLineWidth(context, stroke_w);
                CGContextSetLineJoin(context, kCGLineJoinRound);
                CGContextSetRGBFillColor(context, clr_stroke.r / 255.0, clr_stroke.g / 255.0, clr_stroke.b / 255.0, clr_stroke.a / 255.0);
                CGContextSetRGBStrokeColor(context, clr_stroke.r / 255.0, clr_stroke.g / 255.0, clr_stroke.b / 255.0, clr_stroke.a / 255.0);
                CGContextSetTextDrawingMode(context, kCGTextStroke);
                
                [str drawAtPoint:CGPointMake(x, y + 1) withFont:ft];
            }
            
            // 填充
            CGContextSetTextDrawingMode(context, kCGTextFill);
            CGContextSetRGBFillColor(context, clr_fore.r / 255.0, clr_fore.g / 255.0, clr_fore.b / 255.0, 1.0);
            [str drawAtPoint:CGPointMake(x, y) withFont:ft];
            
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
    
    // 清理
    UIGraphicsPopContext();
    CGColorSpaceRelease(colorspace);
    CGContextRelease(context);
    
    return true;

}

bool ZQTextUtilIOS::renderByString(cocos2d::Sprite *sprite, const std::string &info, int width, int height)
{
    return false;
}

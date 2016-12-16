
#import "ConsoleWindowController.h"

@interface ConsoleWindowController ()

@end

#define SKIP_LINES_COUNT    3
#define MAX_LINE_LEN        4096
#define MAX_LINES_COUNT     200

@implementation ConsoleWindowController
@synthesize textView;

- (id)initWithWindow:(NSWindow *)window
{
    self = [super initWithWindow:window];
    if (self)
    {
        // Initialization code here.
        linesCount = [[NSMutableArray arrayWithCapacity:MAX_LINES_COUNT + 1] retain];
    }

    return self;
}

- (void)dealloc
{
    [linesCount release];
    [super dealloc];
}

- (void)windowDidLoad
{
    [super windowDidLoad];
    // Implement this method to handle any initialization after your window controller's window has been loaded from its nib file.
}

- (void) trace:(NSString*)msg
{
    if (traceCount >= SKIP_LINES_COUNT && [msg length] > MAX_LINE_LEN)
    {
        msg = [NSString stringWithFormat:@"%@ ...", [msg substringToIndex:MAX_LINE_LEN - 4]];
    }
    traceCount++;
    
    NSUInteger bPreMode = 0;
    NSArray *array = [msg componentsSeparatedByString:@"\n"];
    for (NSUInteger i = 0; i < [array count]; i++) {
        NSString* item = [[array objectAtIndex:i] stringByAppendingString:@"\n"];
        NSFont *font = [NSFont fontWithName:@"Monaco" size:12.0];
        //    NSDictionary *attrsDictionary = [NSDictionary dictionaryWithObject:font forKey:NSFontAttributeName];
        NSColor *txtColor = [NSColor blackColor];
        if ([item containsString:@"[ERROR]"]) {
            txtColor = [NSColor redColor];
            bPreMode = 1;
        } else if ([item containsString:@"[DEBUG]"]) {
            txtColor = [NSColor blueColor];
            bPreMode = 2;
        } else {
            if (bPreMode == 1) {
                txtColor = [NSColor redColor];
            } else if (bPreMode == 2) {
                txtColor = [NSColor blueColor];
            }
        }
        
        NSFont *txtFont = [NSFont fontWithName:@"Monaco" size:12.0];
        NSDictionary *attrsDictionary = [NSDictionary dictionaryWithObjectsAndKeys:txtFont,
                                         NSFontAttributeName, txtColor,
                                         NSForegroundColorAttributeName, nil];
        
        NSAttributedString *string = [[NSAttributedString alloc] initWithString:item attributes:attrsDictionary];
        NSNumber *len = [NSNumber numberWithUnsignedInteger:1];
        [linesCount addObject:len];
        
        //    [textView setTextColor:[NSColor redColor]];
        NSTextStorage *storage = [textView textStorage];
        [storage beginEditing];
        [storage appendAttributedString:string];
        
        if ([linesCount count] >= MAX_LINES_COUNT)
        {
            len = [linesCount objectAtIndex:0];
            [storage deleteCharactersInRange:NSMakeRange(0, [len unsignedIntegerValue])];
            [linesCount removeObjectAtIndex:0];
        }
        
        [storage endEditing];
        [self changeScroll];
    }
    
}

//- (void) trace:(NSString*)msg
//{
//    if (traceCount >= SKIP_LINES_COUNT && [msg length] > MAX_LINE_LEN)
//    {
//        msg = [NSString stringWithFormat:@"%@ ...", [msg substringToIndex:MAX_LINE_LEN - 4]];
//    }
//    traceCount++;
//    
//    NSFont *font = [NSFont fontWithName:@"Monaco" size:12.0];
////    NSDictionary *attrsDictionary = [NSDictionary dictionaryWithObject:font forKey:NSFontAttributeName];
//    NSColor *txtColor = [NSColor blackColor];
//    if ([msg containsString:@"[ERROR]"]) {
//        txtColor = [NSColor redColor];
//    } else if ([msg containsString:@"[DEBUG]"]) {
//        txtColor = [NSColor blueColor];
//    }
//    
//    NSFont *txtFont = [NSFont fontWithName:@"Monaco" size:12.0];
//    NSDictionary *attrsDictionary = [NSDictionary dictionaryWithObjectsAndKeys:txtFont,
//                          NSFontAttributeName, txtColor,
//                          NSForegroundColorAttributeName, nil];
//    
//    NSAttributedString *string = [[NSAttributedString alloc] initWithString:msg attributes:attrsDictionary];
//    NSNumber *len = [NSNumber numberWithUnsignedInteger:[string length]];
//    [linesCount addObject:len];
//
////    [textView setTextColor:[NSColor redColor]];
//	NSTextStorage *storage = [textView textStorage];
//	[storage beginEditing];
//	[storage appendAttributedString:string];
//
//    if ([linesCount count] >= MAX_LINES_COUNT)
//    {
//        len = [linesCount objectAtIndex:0];
//        [storage deleteCharactersInRange:NSMakeRange(0, [len unsignedIntegerValue])];
//        [linesCount removeObjectAtIndex:0];
//    }
//
//	[storage endEditing];
//    [self changeScroll];
//}

- (void) changeScroll
{
    BOOL scroll = [checkScroll state] == NSOnState;
    if(scroll)
    {
        [self.textView scrollRangeToVisible: NSMakeRange(self.textView.string.length, 0)];
    }
}

- (IBAction)onClear:(id)sender
{
    NSTextStorage *storage = [textView textStorage];
    [storage setAttributedString:[[[NSAttributedString alloc] initWithString:@""] autorelease]];
}

- (IBAction)onScrollChange:(id)sender
{
    [self changeScroll];
}

- (IBAction)onTopChange:(id)sender
{
    BOOL isTop = [topCheckBox state] == NSOnState;
    if(isTop)
    {
        [self.window setLevel:NSFloatingWindowLevel];
    }
    else
    {
        [self.window setLevel:NSNormalWindowLevel];
    }
}

@end

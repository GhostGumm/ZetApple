//
//  FrameworkOsx.h
//  FrameworkOsx
//
//  Created by Hakim on 20/07/15.
//  Copyright (c) 2015 Hakim. All rights reserved.
//

#import <Cocoa/Cocoa.h>

//! Project version number for FrameworkOsx.
FOUNDATION_EXPORT double FrameworkOsxVersionNumber;

//! Project version string for FrameworkOsx.
FOUNDATION_EXPORT const unsigned char FrameworkOsxVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <FrameworkOsx/PublicHeader.h>

#import <Foundation/Foundation.h>
#import "libZeta.h"
#import "jansson.h"
#import  "ZetaInit.h"
#import "ZetaRequest.h"

@interface  Frame : NSObject
{
    
    @public char *toto;
    
}

- (void)Greetings;
- (void)Test;

@end
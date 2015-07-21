//
//  NSObject+FrameworkOsx_framework.m
//  FrameworkOsx
//
//  Created by Hakim on 21/07/15.
//  Copyright (c) 2015 Hakim. All rights reserved.
//

#import "FrameworkOsx.h"

@implementation Frame

- (void) Greetings{
    NSLog(@"ready to test the framework");
}

- (void)Test{
    self->toto = "toto";
    printf("toto = %s\n", self->toto);
}

@end

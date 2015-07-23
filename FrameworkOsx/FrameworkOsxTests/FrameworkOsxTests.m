//
//  FrameworkOsxTests.m
//  FrameworkOsxTests
//
//  Created by Hakim on 20/07/15.
//  Copyright (c) 2015 Hakim. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import "ZetaInit.h"

typedef bool (*cometd_subscription_callback)(cometd_client_t * client, cometd_message * message);

@interface FrameworkOsxTests : XCTestCase

@end

@implementation FrameworkOsxTests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void) ExecuteFunc{
    NSLog(@"fuck");
}

- (void) ExecuteAll{
}

- (void)testExample {
    
    // This is an example of a functional test case.
    XCTAssert(YES, @"Pass");
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}


@end

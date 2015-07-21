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

    ZetaInit *Test;
    
    NSLog(@"testing shit");
    cometd_subscription_callback totolacallback;
    [Test ZetaInit];
    [Test ZetaInitHandshake:"GmY-HuzW" DeploymentId:"KZyH" Login:"test2" Password:"password"];
    [Test ZetaClient:"http://m.zpush.ovh:8080/str/strd" Transport:NULL BusinessId:"GmY-HuzW" HandShakeManager:Test->hm resource:"zetaTuto"];
    cometd_channel_subscribe(Test->client->cometClient, totolacallback, "/channel/channel");
    //[Test ZetaSubscriber:Test->client->cometClient CallBacker:@selector(ExecuteFunc) Channel:"/servi\
     ce/GmY-HuzW/2v_u/execute"];
    if (!zeta_handshake(Test->client)){
        while (![Test ZetaMainLoop:Test->client])
            cometd_execute_request(Test->client->cometClient, Test->hm, "2v_u" , malloc(sizeof(char*) + 4) , NULL, "ShDmD1_ZFwNnmmjLxJCroA", "resource0","ShDmD1_ZFwNnmmjLxJCroA", "resource1");
    }
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

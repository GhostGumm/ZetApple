//
//  NSObject+Wrapper.h
// 
//
//  Created by Hakim on 20/07/15.
//  Copyright (c) 2015 Hakim. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "libZeta.h"
#import "jansson.h"


@interface ZetaInit: NSObject{
    
@public zeta_handshake_manager_t            *hm;
@public zeta_client_t                       *client;
@public cometd_client_impl                  *cli;
@public const char                                *_Bid;
@public const char                                *_DepId;
@public const char                                *_Login;
@public const char                                *_Password;
    
}

- (int)ZetaInit;

- (zeta_handshake_manager_t *)ZetaInitHandshake:(const char *)BId DeploymentId:(const char *)DepId Login:(const char *)Login Password:(const char *)Pass;
- (zeta_client_t *)ZetaClient:(const char *)Server Transport:(void *)Transport resource:(const char *)resource;

- (void)ZetaSubscriber:(cometd_subscription_callback)CallBack Channel:(char *)Channel;

- (bool)ZetaHanshake;

- (bool)ZetaMainLoop;


/*------------------ Comet Calls -----------------*/



/*----- Remoting ----*/

- (bool)ExecuteAction:(char *)SDepId Cmd:(char *)cmd ExtraData:(HashMaps *)data Adresser:(char *)From AdresserResource:(char *)ResOrigin Owner:(char *)Owner Resource:(char *)Resource;

- (bool)PongAction:(char *)SDepId Action:(char *)Action Avaibility:(bool)Avaible Owner:(char *)Owner Resource:(char *)Resource Uid:(char *)Uid User:(char *)User;

- (bool)PingAction:(char *)SDepId Action:(char *)Action;


/*----- Remoting ----*/

/*----- Macro -------*/

- (bool)MacroCallAction:(const char *)SDepId Name:(char *)Name Parameters:(HashMaps *)Params;

/*----- Macro -------*/


/*------ Group ------*/

- (bool)CreatGroupAction:(const char *)SDepId Group:(char *)Group GroupName:(char *)GroupName Owner:(char *)Owner;

- (bool)AllGroupsAction:(const char *)SDepId Owner:(char *)Owner;

- (bool)MyGroupsAction:(const char *)SDepId Owner:(char *)Owner;

- (bool)GroupUsersAction:(const char *)SDepId Group:(char *)Group Owner:(char *)Owner;

- (bool)DeleteGroupAction:(const char *)SDepId Group:(char *)Group Owner:(char *)Owner;

- (bool)AddMeAsUserAction:(const char *)SDepId Group:(char *)Group Owner:(char *)Owner User:(char *)User;

- (bool)AddUsersToGroupAction:(const char *)SDepId Group:(char *)Group GroupName:(char *)GroupName Owner:(char *)Owner UsersToAdd:(HashMaps *)Users;

- (bool)DeleteUserAction:(const char *)SDepId Group:(char *)Group Owner:(char *)Owner UserToDelete:(char *)User;

- (bool)DeleteMultipleUserAction:(const char *)SDepId Group:(char *)Group GroupName:(char *)GroupName Owner:(char *)Owner Users:(HashMaps *)Users;

- (bool)GrantOrRevokeFromGroup:(const char *)SDepId Action:(char *)Action Group:(char *)Group Owner:(char *)Owner Resource:(char *)Resource TrueForRevokeFalseForGrant:(bool)GOR;

- (bool)ListGrantsAction:(const char *)SDepId Action:(HashMaps *)Action Group:(char *)Group Owner:(char *)Owner Resource:(char *)Resource Bool:(char *)RORG; //List_Grant_Data

- (bool)ShowMyGroupsAction:(const char *)SDepId Owner:(const char *)Owner;


/*----- Group -------*/


/*----- Queue -------*/

- (bool)QueueDoneAction:(const char *)SDepId Result:(HashMaps *)Result Success:(bool)Success IdOfTask:(char *)TaskId;

- (bool)QueueSubmitAction:(const char *)SDepId Origin:(OwnerRessource *)Origin Description:(char *)Desc OriginBid:(char *)OriginBId OriginDepId:(char *)OrigDep Data:(HashMaps *)Data;

- (bool)QueueRegisterAction:(const char *)SDepId Capacity:(int)Capacity;

- (bool)MessagingSendAction:(const char *)SDepId Message:(char *)Message Target:(char *)Target;

/*------ Queue Unregister -----*/

/*----- Queue End -----*/

/*----- Stack -----*/

- (bool)GetListenersAction:(const char *)SDepId Stack:(char *)Stack Owner:(char *)Owner;

- (bool)SetListenersAction:(const char *)SDepId SetString:(HashMaps *)SetString Stack:(char *)Stack Owner:(char *)Owner;

- (bool)StackRemove:(const char *)SDepId GuidList:(HashMaps *)GuidList Stack:(char *)Stack Owner:(char *)Owner;

- (bool)StackPush:(const char *)SDepId Guid:(char *)Guid Stack:(char *)Stack Data:(HashMaps *)Data  Owner:(char *)Owner;

- (bool)StackList:(const char *)SDepId Stack:(char *)Stack Page:(char *)Page Owner:(char *)Owner;


/*----- Stack End -----*/

/*----- Gda ----- */

- (bool)GdaListAction:(const char *)SDepId Table:(char *)Table Column:(char *)Column PageNumber:(char *)PNum PageSize:(char *)PSize;
- (bool) GdaPutAction:(const char *)SDepId Table:(char *)Table Column:(char *)Column Key:(char *)Key Key2:(char *)Key2 YourData:(HashMaps *)YourData;
- (bool)GdaGetAction:(const char *)SDepId Table:(char *)Table Column:(char *)Column Key:(char *)Key Key2:(char *)Key2;

- (bool) ListFolder:(char *)Folder SDepId:(char *)SDepId;

- (bool) Echo:(char *)Request SDepId:(char *)SDepId;
/*------------------------------------------------*/




@end
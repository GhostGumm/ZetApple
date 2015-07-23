//
//  NSObject+Wrapper.m
//  
//
//  Created by Hakim on 20/07/15.
//  Copyright (c) 2015 Hakim. All rights reserved.
//

#import "ZetaInit.h"



@implementation ZetaInit

/*-------- Init Part ------- */

- (int)ZetaInit
{
    if (cometd_init())
        printf("Cometd_init failed\n");
    
    return (cometd_init());
}

- (zeta_handshake_manager_t *)ZetaInitHandshake:(const char *)BId DeploymentId:(const char *)DepId Login:(const char *)Login Password:(const char *)Pass
{
    self->_Bid = BId;
    self->_DepId = DepId;
    self->_Login = Login;
    self->_Password = Pass;
    
    if (BId && DepId && Login && Pass){
        self->hm = zeta_create_mem_handshake_manager(BId, DepId, Login, Pass);
        return (self->hm);
    }
    else
        return NULL;
}

- (zeta_client_t *)ZetaClient:(const char *)Server Transport:(void *)Transport resource:(const char *)resource
{
    if (Server && resource){
        self->client = zeta_create_client(Server, cometd_create_long_polling_transport(), self->_Bid, self->hm, resource);
        return self->client;
    }
    else
        return (self->client);
}

- (void)ZetaSubscriber:(cometd_subscription_callback)CallBack Channel:(char *)Channel
{
    cometd_channel_subscribe(self->client->cometClient, CallBack, Channel);
    NSLog(@"CallBack subscribed to : ");
    printf("CallBack Observer set for : %s\n", Channel);
}

- (bool)ZetaHanshake
{
        if (!zeta_handshake(self->client)){
            self->cli = (cometd_client_impl *)self->client->cometClient;
            return false;
        }
        else{
            printf("Cometd Handshake Failed\n");
            return true;
        }
}

- (bool)ZetaMainLoop
{
    
    return (cometd_main_loop(self->client->cometClient));
}

/*--------- Requests Parts ----------- */


- (bool)ExecuteAction: (char *)SDepId Cmd:(char *)Cmd ExtraData:(HashMaps *)Data Adresser:(char *)From AdresserResource:(char *)ResOrigin Owner:(char *)Owner Resource:(char *)Resource
{
    return cometd_execute_request(self->client->cometClient, self->hm, SDepId, Cmd, Data, From, ResOrigin, Owner, Resource);
}

- (bool)PongAction: (char *)SDepId Action:(char *)Action Avaibility:(bool)Avaible Owner:(char *)Owner Resource:(char *)Resource Uid:(char *)Uid User:(char *)User
{
    return cometd_pong_request(self->client->cometClient, self->hm, SDepId, Action,  Avaible, Owner, Resource, Uid, User);
}

- (bool)PingAction:(char *)SDepId Action:(char *)Action
{
    return cometd_ping_request(self->client->cometClient, self->hm, SDepId, Action);
}


/*----- Remoting ----*/

/*----- Macro -------*/

- (bool)MacroCallAction:  (const char *)SDepId Name:(char *)Name Parameters:(HashMaps *)Params
{
    return cometd_macro_call_request(self->client->cometClient, self->hm, SDepId, Name, Params);
}

/*----- Macro -------*/


/*------ Group ------*/

- (bool)CreatGroupAction:  (const char *)SDepId Group:(char *)Group GroupName:(char *)GroupName Owner:(char *)Owner
{
    return cometd_group_create_request(self->client->cometClient, self->hm, SDepId, Group, GroupName, Owner);
}

- (bool)AllGroupsAction:  (const char *)SDepId Owner:(char *)Owner
{
    return cometd_all_groups_request(self->client->cometClient, self->hm, SDepId, Owner);
}

- (bool)MyGroupsAction:(const char *)SDepId Owner:(char *)Owner
{
    return cometd_groups_request(self->client->cometClient, self->hm, SDepId, Owner);
}

- (bool)GroupUsersAction:  (const char *)SDepId Group:(char *)Group Owner:(char *)Owner
{
    return cometd_group_users_request(self->client->cometClient, self->hm, SDepId, Group, Owner);
}

- (bool)DeleteGroupAction:  (const char *)SDepId Group:(char *)Group Owner:(char *)Owner
{
    return cometd_group_del_request(self->client->cometClient, self->hm, SDepId, Group, Owner);
}

- (bool)AddMeAsUserAction:(const char *)SDepId Group:(char *)Group Owner:(char *)Owner User:(char *)User
{
    return cometd_add_me_request(self->client->cometClient, self->hm, SDepId, Group, Owner, User);
}

- (bool)AddUsersToGroupAction:(const char *)SDepId Group:(char *)Group GroupName:(char *)GroupName Owner:(char *)Owner UsersToAdd:(HashMaps *)Users
{
    return cometd_group_add_users_request(self->client->cometClient, self->hm, SDepId, Group, GroupName, Owner, Users);
}

- (bool)DeleteUserAction:(const char *)SDepId Group:(char *)Group Owner:(char *)Owner UserToDelete:(char *)User
{
    return cometd_group_del_user_request(self->client->cometClient, self->hm, SDepId, Group, Owner, User);
}

- (bool)DeleteMultipleUserAction:(const char *)SDepId Group:(char *)Group GroupName:(char *)GroupName Owner:(char *)Owner User:(HashMaps *)Users
{
    return cometd_group_del_users_request(self->client->cometClient, self->hm, SDepId, Group, GroupName, Owner, Users);
}

- (bool)GrantOrRevokeFromGroup:(const char *)SDepId Action:(char *)Action Group:(char *)Group Owner:(char *)Owner Resource:(char *)Resource TrueForRevokeFalseForGrant:(bool)GOR
{
    return cometd_group_revoke_and_grant_request(self->client->cometClient, self->hm, SDepId, Action, Group, Owner, Resource, GOR);
}

- (bool)ListGrantsAction:(const char *)SDepId Action:(HashMaps *)Action Group:(char *)Group Owner:(char *)Owner Resource:(char *)Resource Bool:(char *)RORG
{
    return cometd_group_list_grant_request(self->client->cometClient, self->hm, SDepId, Action, Group, Owner, Resource, RORG);
}

- (bool)ShowMyGroupsAction:(const char *)SDepId Owner:(const char *)Owner
{
    return cometd_my_groups_request(self->client->cometClient, self->hm, SDepId, Owner);
}


/*----- Group -------*/


/*----- Queue -------*/

- (bool)QueueDoneAction:(const char *)SDepId Result:(HashMaps *)Result Success:(bool)Success IdOfTask:(char *)TaskId
{
    return cometd_queue_done_request(self->client->cometClient, self->hm, SDepId, Result, Success, TaskId);
}

- (bool)QueueSubmitAction:  (const char *)SDepId Origin:(OwnerRessource *)Origin Description:(char *)Desc OriginBid:(char *)OriginBId OriginDepId:(char *)OrigDep Data:(HashMaps *)Data
{
    return cometd_queue_submit_request(self->client->cometClient, self->hm, SDepId, Origin, Desc, OriginBId, OrigDep, Data);
}

- (bool)QueueRegisterAction:  (const char *)SDepId Capacity:(int)Capacity
{
    return cometd_queue_register_request(self->client->cometClient, self->hm, SDepId, Capacity);
}

- (bool)MessagingSendAction:(const char *)SDepId Message:(char *)Message Target:(char *)Target
{
    return cometd_request_messaging(self->client->cometClient, self->hm, SDepId, Target, Message);
}

/*------ Queue Unregister -----*/

/*----- Queue End -----*/

/*----- Stack -----*/

- (bool)GetListenersAction:  (const char *)SDepId Stack:(char *)Stack Owner:(char *)Owner
{
    return cometd_stack_get_listeners_request(self->client->cometClient, self->hm, SDepId, Stack, Owner);
}

- (bool)SetListenersAction:  (const char *)SDepId SetString:(HashMaps *)SetString Stack:(char *)Stack Owner:(char *)Owner
{
    return cometd_stack_set_listeners_request(self->client->cometClient, self->hm, SDepId, SetString, Stack, Owner);
}

- (bool)StackRemove:(const char *)SDepId GuidList:(HashMaps *)GuidList Stack:(char *)Stack Owner:(char *)Owner
{
    return  cometd_stack_remove_request(self->client->cometClient, self->hm, SDepId, GuidList, Stack, Owner);
}

- (bool)StackPush:(const char *)SDepId Guid:(char *)Guid Stack:(char *)Stack Data:(HashMaps *)Data  Owner:(char *)Owner
{
    return cometd_stack_push_request(self->client->cometClient, self->hm, SDepId, Guid, Stack, Data, Owner);
}

- (bool)StackList:(const char *)SDepId Stack:(char *)Stack Page:(char *)Page Owner:(char *)Owner
{
    return cometd_stack_listing_request(self->client->cometClient, self->hm, SDepId, Stack, Page, Owner);
}

/*----- Stack End -----*/

/*----- Gda ----- */

- (bool)GdaListAction:  (const char *)SDepId Table:(char *)Table Column:(char *)Column PageNumber:(char *)PNum PageSize:(char *)PSize
{
    return cometd_request_list_gda(self->client->cometClient, self->hm, SDepId, Table, Column, PNum, PSize);
}

- (bool) GdaPutAction:  (const char *)SDepId Table:(char *)Table Column:(char *)Column Key:(char *)Key Key2:(char *)Key2 YourData:(HashMaps *)YourData
{
    return cometd_request_put_gda(self->client->cometClient, self->hm, SDepId, Table, Column, Key, Key2, YourData);
}

- (bool)GdaGetAction:  (const char *)SDepId Table:(char *)Table Column:(char *)Column Key:(char *)Key Key2:(char *)Key2
{
    return cometd_request_get_gda(self->client->cometClient, self->hm, SDepId, Table, Column, Key, Key2);
}

- (bool) Echo:(char *)Request SDepId:(char *)SDepId
{
    return cometd_request_echo(self->client->cometClient, self->hm, Request, SDepId);
}

- (bool) ListFolder:(char *)Folder SDepId:(char *)SDepId
{
    return cometd_request_ls(self->client->cometClient, self->hm, Folder, SDepId);
}

/*----------------------- */






@end

//
//  RNCarPlay.h
//  RNCarPlay
//
//  Created by Birkir Gudjonsson on 3/25/19.
//  Copyright © 2019 SOLID Mobile. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CarPlay/CarPlay.h>
#import <React/RCTBridgeModule.h>
#import <React/RCTEventEmitter.h>
#import "RNCPStore.h"

typedef void(^SearchResultUpdateBlock)(NSArray<CPListItem *> * _Nonnull);
typedef void(^SelectedResultBlock)(void);

@interface RNCarPlay : RCTEventEmitter<RCTBridgeModule, CPInterfaceControllerDelegate, CPSearchTemplateDelegate, CPListTemplateDelegate> {
    CPInterfaceController *interfaceController;
    CPWindow *window;
    SearchResultUpdateBlock searchResultBlock;
    SelectedResultBlock selectedResultBlock;
}

@property (nonatomic, retain) CPInterfaceController *interfaceController;
@property (nonatomic, retain) CPWindow *window;
@property (nonatomic, copy) SearchResultUpdateBlock searchResultBlock;
@property (nonatomic, copy) SelectedResultBlock selectedResultBlock;

+ (void) registerWithInterfaceController:(CPInterfaceController*)interfaceController window:(CPWindow*)window;
- (NSArray<CPListSection*>*) parseSections:(NSArray*)sections;

@end

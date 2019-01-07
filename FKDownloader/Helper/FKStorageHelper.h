//
//  FKStorageHelper.h
//  FKDownloader
//
//  Created by norld on 2019/1/3.
//  Copyright © 2019 Norld. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FKTaskProtocol.h"

typedef struct FKTaskBaseInfo {
    uint64_t number;
    long type;
    uint64_t length;
    char *identifier;
} FKTaskBaseInfo;

typedef struct FKGroupTaskComponent {
    char *link;
    char *tmp;
} FKGroupTaskComponent;

typedef struct FKDripTaskComponent {
    uint64_t idx;
    uint16_t start;
    uint16_t end;
    char *tmp;
} FKDripTaskComponent;

typedef struct FKSingleTaskInfo {
    FKTaskBaseInfo base;
    char *link;
    char *tmp;
    char *ext;
} FKSingleTaskInfo;

typedef struct FKGroupTaskInfo {
    FKTaskBaseInfo base;
    uint16_t count;
    FKGroupTaskComponent *components;
} FKGroupTaskInfo;

typedef struct FKDripTaskInfo {
    FKTaskBaseInfo base;
    FKDripTaskComponent *components;
    uint16_t count;
    char *link;
    char *ext;
} FKDripTaskInfo;

NS_ASSUME_NONNULL_BEGIN

@interface FKStorageHelper : NSObject

+ (void)saveTask:(id<FKTaskProtocol>)task;
+ (id<FKTaskProtocol>)loadTaskWithIdentifier:(NSString *)identifier;

//+ (void)saveResumeDataWithTask:(id<FKTaskProtocol>)task;
//+ (void)loadResumeDataWithTask:(id<FKTaskProtocol>)task;

@end

NS_ASSUME_NONNULL_END

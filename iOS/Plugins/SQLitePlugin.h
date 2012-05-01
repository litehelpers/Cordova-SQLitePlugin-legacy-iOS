/*
 * Copyright (C) 2011 Davide Bertola
 *
 * Authors:
 * Davide Bertola <dade@dadeb.it>
 * Joe Noon <joenoon@gmail.com>
 *
 * This library is available under the terms of the MIT License (2008). 
 * See http://opensource.org/licenses/alphabetical for full text.
 */

#import <Foundation/Foundation.h>
#import "sqlite3.h"

#ifdef CORDOVA_FRAMEWORK
#import <CORDOVA/CDVPlugin.h>
#import <CORDOVA/JSONKit.h>
#import <CORDOVA/CDVFile.h>
#else
#import "CDVPlugin.h"
#import "JSONKit.h"
#import "CDVFile.h"
#endif

#ifdef DEBUG
#   define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#   define DLog(...)
#endif

#import "AppDelegate.h"

@interface SQLitePlugin : CDVPlugin {
    NSMutableDictionary *openDBs;
}

@property (nonatomic, copy) NSMutableDictionary *openDBs;
@property (nonatomic, retain) NSString *appDocsPath;

-(void) log:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
-(void) open:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
-(void) backgroundExecuteSqlBatch:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
-(void) backgroundExecuteSql:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
-(void) executeSqlBatch:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
-(void) executeSql:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
-(void) _executeSqlBatch:(NSMutableDictionary*)options;
-(void) _executeSql:(NSMutableDictionary*)options;
-(void) close: (NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
-(void) respond: (id)cb withString:(NSString *)str withType:(NSString *)type;
-(id) getDBPath:(id)dbFile;

@end

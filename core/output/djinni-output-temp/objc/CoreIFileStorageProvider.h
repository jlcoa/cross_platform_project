// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_file_storage_provider.djinni

#import <Foundation/Foundation.h>


/** log */
@protocol CoreIFileStorageProvider

- (nonnull NSString *)getDocumentsPath:(nonnull NSString *)relativePath;

- (void)createRelativeFolder:(nonnull NSString *)relativePath;

- (void)remove:(nonnull NSString *)path;

@end

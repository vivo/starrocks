// This file is licensed under the Elastic License 2.0. Copyright 2021-present, StarRocks Limited.

#include "common/s3_uri.h"

#include <gtest/gtest.h>

#include "testutil/parallel_test.h"

namespace starrocks {

PARALLEL_TEST(S3URITest, virtual_host_url) {
    S3URI uri;
    ASSERT_TRUE(uri.parse("https://mybucket.s3.us-west-2.amazonaws.com/puppy.png"));
    EXPECT_EQ("https", uri.schema());
    EXPECT_EQ("us-west-2", uri.region());
    EXPECT_EQ("mybucket", uri.bucket());
    EXPECT_EQ("puppy.png", uri.key());
    EXPECT_EQ("s3.us-west-2.amazonaws.com", uri.endpoint());
}

PARALLEL_TEST(S3URITest, path_style_url) {
    S3URI uri;
    ASSERT_TRUE(uri.parse("https://s3.us-west-2.amazonaws.com/mybucket/puppy.jpg"));
    EXPECT_EQ("https", uri.schema());
    EXPECT_EQ("us-west-2", uri.region());
    EXPECT_EQ("mybucket", uri.bucket());
    EXPECT_EQ("puppy.jpg", uri.key());
    EXPECT_EQ("s3.us-west-2.amazonaws.com", uri.endpoint());
}

PARALLEL_TEST(S3URITest, s3_schema) {
    S3URI uri;
    ASSERT_TRUE(uri.parse("s3://mybucket/puppy.jpg"));
    EXPECT_EQ("s3", uri.schema());
    EXPECT_EQ("", uri.region());
    EXPECT_EQ("mybucket", uri.bucket());
    EXPECT_EQ("puppy.jpg", uri.key());
    EXPECT_EQ("", uri.endpoint());
}

PARALLEL_TEST(S3URITest, virtual_host_non_s3_url) {
    S3URI uri;
    ASSERT_TRUE(uri.parse("https://examplebucket.oss-cn-hangzhou.aliyuncs.com/exampledir/example.txt"));
    EXPECT_EQ("https", uri.schema());
    EXPECT_EQ("", uri.region());
    EXPECT_EQ("examplebucket", uri.bucket());
    EXPECT_EQ("exampledir/example.txt", uri.key());
    EXPECT_EQ("oss-cn-hangzhou.aliyuncs.com", uri.endpoint());
}

PARALLEL_TEST(S3URITest, with_query_and_fragment) {
    S3URI uri;
    ASSERT_TRUE(uri.parse("https://examplebucket.oss-cn-hangzhou.aliyuncs.com/exampledir/example.txt?a=b#xyz"));
    EXPECT_EQ("https", uri.schema());
    EXPECT_EQ("", uri.region());
    EXPECT_EQ("examplebucket", uri.bucket());
    EXPECT_EQ("exampledir/example.txt", uri.key());
    EXPECT_EQ("oss-cn-hangzhou.aliyuncs.com", uri.endpoint());
}

PARALLEL_TEST(S3URITest, empty) {
    S3URI uri;
    ASSERT_FALSE(uri.parse(""));
}

PARALLEL_TEST(S3URITest, missing_schema) {
    S3URI uri;
    ASSERT_FALSE(uri.parse("/bucket/puppy.jpg"));
}

} // namespace starrocks

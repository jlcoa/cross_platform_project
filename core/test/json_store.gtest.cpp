#include <gtest/gtest.h>
#include "stl.hpp"
#include "src/db/sqlite_store.hpp"
using json11::Json;

TEST(json_store, can_get_and_set) {
    shared_ptr<core::JsonStore> db = make_shared<core::SqliteStore>(":memory:");
    Json value = db->get("nothing");
    EXPECT_EQ(value.is_null(), true) << "should return null for non-existent values";

    db->set("A", 15);
    Json v = db->get("A");
    EXPECT_EQ(v.int_value(), 15);
}

TEST(json_store, can_set_twice) {
    shared_ptr<core::JsonStore> db = make_shared<core::SqliteStore>(":memory:");
    Json value = db->get("nothing");
    EXPECT_EQ(value.is_null(), true) << "should return null for non-existent values";

    db->set("A", 15);
    db->set("B", 16);
    db->set("A", 17);
    Json v = db->get("A");
    EXPECT_EQ(v.int_value(), 17);
}

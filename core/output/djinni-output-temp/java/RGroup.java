// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from model.djinni

package com.nextuc;

import java.util.ArrayList;

/** group */
public final class RGroup {

    public static final String TYPE_GROUP = "TeamRoom";


    /*package*/ final String mId;

    /*package*/ final String mGroupName;

    /*package*/ final String mGroupType;

    /*package*/ final ArrayList<String> mUserIds;

    /*package*/ final ArrayList<String> mOwner;

    /*package*/ final ArrayList<String> mAdmin;

    public RGroup(
            String id,
            String groupName,
            String groupType,
            ArrayList<String> userIds,
            ArrayList<String> owner,
            ArrayList<String> admin) {
        this.mId = id;
        this.mGroupName = groupName;
        this.mGroupType = groupType;
        this.mUserIds = userIds;
        this.mOwner = owner;
        this.mAdmin = admin;
    }

    public String getId() {
        return mId;
    }

    public String getGroupName() {
        return mGroupName;
    }

    public String getGroupType() {
        return mGroupType;
    }

    /**	membersCount: optional<i64>; */
    public ArrayList<String> getUserIds() {
        return mUserIds;
    }

    public ArrayList<String> getOwner() {
        return mOwner;
    }

    public ArrayList<String> getAdmin() {
        return mAdmin;
    }

    @Override
    public String toString() {
        return "RGroup{" +
                "mId=" + mId +
                "," + "mGroupName=" + mGroupName +
                "," + "mGroupType=" + mGroupType +
                "," + "mUserIds=" + mUserIds +
                "," + "mOwner=" + mOwner +
                "," + "mAdmin=" + mAdmin +
        "}";
    }

}

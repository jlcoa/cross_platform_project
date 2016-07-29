// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from date.djinni

package com.dropbox.djinni.test;

import javax.annotation.CheckForNull;
import javax.annotation.Nonnull;

public final class DateRecord implements Comparable<DateRecord> {


    /*package*/ final java.util.Date mCreatedAt;

    public DateRecord(
            @Nonnull java.util.Date createdAt) {
        this.mCreatedAt = createdAt;
    }

    @Nonnull
    public java.util.Date getCreatedAt() {
        return mCreatedAt;
    }

    @Override
    public boolean equals(@CheckForNull Object obj) {
        if (!(obj instanceof DateRecord)) {
            return false;
        }
        DateRecord other = (DateRecord) obj;
        return this.mCreatedAt.equals(other.mCreatedAt);
    }

    @Override
    public int hashCode() {
        // Pick an arbitrary non-zero starting value
        int hashCode = 17;
        hashCode = hashCode * 31 + (mCreatedAt.hashCode());
        return hashCode;
    }

    @Override
    public String toString() {
        return "DateRecord{" +
                "mCreatedAt=" + mCreatedAt +
        "}";
    }


    @Override
    public int compareTo(@Nonnull DateRecord other)  {
        int tempResult;
        tempResult = this.mCreatedAt.compareTo(other.mCreatedAt);
        if (tempResult != 0) {
            return tempResult;
        }
        return 0;
    }
}
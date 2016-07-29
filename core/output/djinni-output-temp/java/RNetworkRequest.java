// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_network_provider.djinni

package com.nextuc;

import java.util.HashMap;

public final class RNetworkRequest {


    /*package*/ final long mRequestID;

    /*package*/ final String mHost;

    /*package*/ final String mPath;

    /*package*/ final ENetworkMethod mRequestMethod;

    /*package*/ final HashMap<String, String> mHeader;

    /*package*/ final String mData;

    public RNetworkRequest(
            long requestID,
            String host,
            String path,
            ENetworkMethod requestMethod,
            HashMap<String, String> header,
            String data) {
        this.mRequestID = requestID;
        this.mHost = host;
        this.mPath = path;
        this.mRequestMethod = requestMethod;
        this.mHeader = header;
        this.mData = data;
    }

    public long getRequestID() {
        return mRequestID;
    }

    public String getHost() {
        return mHost;
    }

    public String getPath() {
        return mPath;
    }

    public ENetworkMethod getRequestMethod() {
        return mRequestMethod;
    }

    public HashMap<String, String> getHeader() {
        return mHeader;
    }

    public String getData() {
        return mData;
    }

    @Override
    public String toString() {
        return "RNetworkRequest{" +
                "mRequestID=" + mRequestID +
                "," + "mHost=" + mHost +
                "," + "mPath=" + mPath +
                "," + "mRequestMethod=" + mRequestMethod +
                "," + "mHeader=" + mHeader +
                "," + "mData=" + mData +
        "}";
    }

}

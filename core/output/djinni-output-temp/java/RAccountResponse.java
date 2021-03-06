// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from model.djinni

package com.nextuc;

public final class RAccountResponse {


    /*package*/ final String mAccessToken;

    /*package*/ final String mRefreshToken;

    /*package*/ final Integer mExpiresIn;

    /*package*/ final RAccount mUser;

    public RAccountResponse(
            String accessToken,
            String refreshToken,
            Integer expiresIn,
            RAccount user) {
        this.mAccessToken = accessToken;
        this.mRefreshToken = refreshToken;
        this.mExpiresIn = expiresIn;
        this.mUser = user;
    }

    public String getAccessToken() {
        return mAccessToken;
    }

    public String getRefreshToken() {
        return mRefreshToken;
    }

    public Integer getExpiresIn() {
        return mExpiresIn;
    }

    public RAccount getUser() {
        return mUser;
    }

    @Override
    public String toString() {
        return "RAccountResponse{" +
                "mAccessToken=" + mAccessToken +
                "," + "mRefreshToken=" + mRefreshToken +
                "," + "mExpiresIn=" + mExpiresIn +
                "," + "mUser=" + mUser +
        "}";
    }

}

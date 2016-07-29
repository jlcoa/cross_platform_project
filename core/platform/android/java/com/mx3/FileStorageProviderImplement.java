package com.mx3;

import android.util.Log;

import com.nextuc.IFileStorageProvider;

import java.io.File;

/**
 * Created by coa.ke on 7/29/16.
 */

public class FileStorageProviderImplement extends IFileStorageProvider {
    @Override
    public String getDocumentsPath(String relativePath) {
        return "";
    }

    @Override
    public void createRelativeFolder(String relativePath) {
        File folder = new File(relativePath);
        boolean success = true;
        if (!folder.exists()) {
            success = folder.mkdir();
        }
        if (success) {
            Log.i("CoaTest", "folder create success");
        } else {
            Log.i("CoaTest", "folder create failed");
        }
    }

    @Override
    public void remove(String path) {
        File dir = new File(path);
        if (dir.isDirectory())
        {
            String[] children = dir.list();
            for (int i = 0; i < children.length; i++)
            {
                new File(dir, children[i]).delete();
            }
        }
    }
}

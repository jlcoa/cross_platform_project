package delegate;

import android.app.Activity;

import com.nextuc.IUiControllerFactory;
import com.nextuc.IXplatformApplication;

/**
 * Created by coa.ke on 7/28/16.
 */

public class NUCUIViewController extends Activity {
    public static IUiControllerFactory getUiControllerFactory () {
        return  IXplatformApplication.sharedApplication().getUiControllerFactory();
    }
}

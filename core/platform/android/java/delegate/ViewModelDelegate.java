package delegate;

import com.nextuc.IViewModelDelegate;

/**
 * Created by coa.ke on 7/28/16.
 */

public class ViewModelDelegate implements IViewModelDelegate {
    private IViewModelDelegate mViewModelDelegate;

    public ViewModelDelegate(IViewModelDelegate mViewModelDelegate) {
        this.mViewModelDelegate = mViewModelDelegate;
    }

    @Override
    public void onDataChanged() {
        mViewModelDelegate.onDataChanged();
    }
}

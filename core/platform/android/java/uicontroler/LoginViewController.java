package uicontroler;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import com.mx3.R;
import com.nextuc.ILoginUiController;
import com.nextuc.ILoginViewModel;
import com.nextuc.IViewModelDelegate;

import delegate.NUCUIViewController;
import delegate.ViewModelDelegate;

/**
 * Created by coa.ke on 7/28/16.
 */

public class LoginViewController extends Activity implements  IViewModelDelegate {
    private ILoginUiController loginUiController;
    private ViewModelDelegate viewModelDelegate;
    private EditText phoneNumber, password;
    private Button loginButton;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.login_screen);
        viewModelDelegate = new ViewModelDelegate(this);
        loginUiController = NUCUIViewController.getUiControllerFactory().createLoginUiController(viewModelDelegate);
        phoneNumber = (EditText) findViewById(R.id.phoneNumberEdit);
        password= (EditText) findViewById(R.id.passwordEdit);
        loginButton = (Button) findViewById(R.id.loginButton);
        loginButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                ILoginViewModel viewModel = loginUiController.getViewModel();
                viewModel.setUserName(phoneNumber.getText().toString());
                viewModel.setPassword(password.getText().toString());

                loginUiController.login();
            }
        });


    }

    @Override
    public void onDataChanged() {
        loginUiController.getViewModel().getStatus();
    }
}

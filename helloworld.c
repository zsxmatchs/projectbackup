    @Override

    public void onCreate(final Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_main);

        mVibrator = (Vibrator) getSystemService(Context.VIBRATOR_SERVICE);



        mTvTips = (TextView) findViewById(R.id.text_identify_user);

        mTvTips.setText(getResources().getString(R.string.fingerdown));

        mBtnOk = (Button) findViewById(R.id.btn_ok);

        mBtnOk.setOnClickListener(mListener);

        mBtnFail = (Button) findViewById(R.id.btn_fail);

        mBtnFail.setOnClickListener(mListener);



        manager = DeviceManager.getDeviceManager(getApplicationContext());



        manager.registerFpCallBack(new DeviceManager.IFpCallBack() {

            @Override

            public void sendMessageToClient(Message msg) {

                Log.e(TAG, "main msg what = " + msg.what + " arg1 = " + msg.arg1 + " arg2 = " + msg.arg2);

                mHandler.sendMessage(msg);
                 Log.e(TAG, "main msg what = " + msg.what + " arg1 = " + msg.arg1 + " arg2 = " + msg.arg2);

            }

        });

    }
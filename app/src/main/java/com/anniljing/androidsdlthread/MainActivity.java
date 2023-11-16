package com.anniljing.androidsdlthread;

import android.os.Bundle;

import com.anniljing.androidsdlthread.databinding.ActivityMainBinding;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'androidsdlthread' library on application startup.
    static {
        System.loadLibrary("androidsdlthread");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        binding.start.setOnClickListener((view) -> startSDLThread());

        binding.post.setOnClickListener((view -> postSDL()));
        binding.release.setOnClickListener((view -> releaseSDL()));
    }

    public native void startSDLThread();

    public native void postSDL();

    public native void releaseSDL();
}
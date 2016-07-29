{ 'targets': [
    {
      'target_name': 'simpleini',
      'type': 'static_library',
      'sources': [
        "simpleini/ConvertUTF.h",
        "simpleini/ConvertUTF.c",
        "simpleini/SimpleIni.h",
      ],
      'cflags': [
        '-fno-rtti',
        '-fno-exceptions',
      ],
      'all_dependent_settings': {
        'include_dirs': [
          '.',
        ]
      },
      'include_dirs': [
        'simpleini',
      ],
    },
  ]
}

{ 'targets': [
    {
      'target_name': 'gtest',
      'type': "static_library",
      'sources': [
        'gtest-1.7.0/src/gtest-all.cc',
        'gtest-1.7.0/src/gtest_main.cc',
      ],
      'cflags_cc!': [ '-Werror' ],
      'xcode_settings': {
        'OTHER_CPLUSPLUSFLAGS!' : ['-Werror'],
      },
      "include_dirs": [
        'gtest-1.7.0',
        'gtest-1.7.0/include',
      ],
      'direct_dependent_settings': {
        'include_dirs': [
          'gtest-1.7.0/include',
        ],
      },
    },
  ]
}


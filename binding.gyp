{
  "targets": [{
    "target_name": "quadnode",
    "cflags!": [ "-fno-exceptions" ],
    "cflags_cc!": [ "-fno-exceptions" ],
    "sources": [
      "addons/quadnode.cc",
	  "addons/addon.cc"
    ],
    "include_dirs": [
      "<!@(node -p \"require('node-addon-api').include\")"
    ],
    "conditions": [
        ["OS=='linux'", {
          "link_settings": {
              "libraries": [
                "-lrt"
                ]
          },
        }]
    ],
    'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
  }]
}

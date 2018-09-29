{
    "targets": [{
        "target_name": "v8json",
        "sources": [
            "main.cc",
            "v8json.cc"
        ],
        "include_dirs": [
            "<!(node -e \"require('nan')\")>"
        ]
    }]
}
# v8-json
V8 JSON Parse/Stringify

[![Travis](https://img.shields.io/travis/rickyes/v8-json.svg?style=for-the-badge)](https://travis-ci.org/rickyes/v8-json)
[![Node Version](https://img.shields.io/badge/node-%3E=8.0.0-brightgreen.svg?longCache=true&style=for-the-badge)](https://www.npmjs.com/package/v8-json)
[![npm](https://img.shields.io/npm/v/v8-json.svg?style=for-the-badge)](https://www.npmjs.com/package/v8-json)


## Install

```bash
$ npm i v8-json --save
```

## Platform
- [x] OSX
- [ ] Linux
- [ ] Windows

## Getting Started
```js
const v = require('v8-json');


v.parse("{\"a\": 1}"); // { "a": 1}

v.stringify({b: true}); // '{"b": true}'

```


## Author
v8-json © [Ricky 泽阳](https://github.com/rickyes), Released under the MIT License.

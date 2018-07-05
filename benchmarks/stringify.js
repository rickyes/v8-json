'use strict';

const os = require('os');
const childProcess = require('child_process');
const v = require('../');

console.log('==========================');
console.log('v8-json: ' + require('../package.json').version);
console.log('CPU: ' + os.cpus().length);
console.log('OS: ' + os.platform() + ' ' + os.arch());
console.log('node version: ' + process.version);
console.log('current commit: ' + childProcess.execSync('git rev-parse --short HEAD'));
console.log('==========================');

let obj = {"test-1": "-1"};
for(let i = 0; i<10000; i++){
  obj[`test${i}`] = `test${i}`;
}
let start = Date.now();
v.stringify(obj);
console.log(`Stringify length: ${Object.keys(obj).length} key`);
console.log('time: '+(Date.now() - start) + ' ms');
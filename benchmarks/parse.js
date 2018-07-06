'use strict';

const os = require('os');
const childProcess = require('child_process');
const v = require('../');

// console.log('==========================');
// console.log('v8-json: ' + require('../package.json').version);
// console.log('CPU: ' + os.cpus().length);
// console.log('OS: ' + os.platform() + ' ' + os.arch());
// console.log('node version: ' + process.version);
// console.log('current commit: ' + childProcess.execSync('git rev-parse --short HEAD'));
// console.log('==========================');

// let str = '{"test-1": "-1",';
// for(let i = 0; i<1000; i++){
//   str += `"test${i}": "${i}",`;
// }
// str = str.slice(0, str.length - 1) + '}';
// let start = Date.now();
// v.parse(str);
// console.log(`Parse length: ${str.length} bit`);
// console.log('time: '+(Date.now() - start) + ' ms');
'use strict';

const v = require('.');
const assert = require('assert');

describe('JSON', () => {
  
  describe('parse', () => {
    
    it('success', (done) => {
      let json = v.parse("{\"a\": 1}");
      assert.equal(json.a, 1);
      done();
    });

    it('failed, Param is Not JSON String!', (done) => {
      try {
        v.parse('');
      } catch (error) {
        assert.equal(error.message, 'Param is Not JSON String!');
      }
      done();
    });

    it('failed, Param is Not String!', (done) => {
      try {
        v.parse(1);
      } catch (error) {
        assert.equal(error.message, 'Param is Not String!');
      }
      done();
    });

  });

  describe('stringify', () => {
    
    it('success', (done) => {
      try {
          let str = v.stringify({a: 1});
          assert.ok(str, '{"a":1}');
      } catch (error) {
        assert.equal(error.message, 'Param is Not JSON String!');
      }
      done();
    });

    it('failed, Param is Not Object!', (done) => {
      try {
        v.stringify(1);
      } catch (error) {
        assert.equal(error.message, 'Param is Not Object!');
      }
      done();
    });    

  });

});
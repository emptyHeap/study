const environments = {};

environments.staging = {
  port: 3000,
  envName: 'staging',
};

environments.production = {
  port: 5000,
  envName: 'production',
};

const {NODE_ENV} = global.process.env;
const selectedEnvironment = NODE_ENV && Object.keys(environments).includes(NODE_ENV)
  ? global.process.env.NODE_ENV
  : 'staging';

module.exports = environments[selectedEnvironment];

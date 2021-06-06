import React, { useState } from 'react';
import Program from './Program/Program';
import PlanList from './PlanList/PlanList';
import Food from './Food/Food';
import Notifications from './Notification/Notifications';
import Account from './Account/Account';
import 'ui-neumorphism/dist/index.css';
import './App.css';

function App() {
  return (
    <div className="App">
      <Program dark = {true}/>
      <PlanList dark = {true}/>
      <Food dark = {true}/>
      <Notifications dark = {true}/>
      <Account dark = {true}/>
    </div>
  );
}

export default App;

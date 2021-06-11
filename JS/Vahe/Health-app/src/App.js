import React, { useState } from 'react';
import Program from './Program/Program';
import PlanList from './PlanList/PlanList';
import Food from './Food/Food';
import Notifications from './Notifications/Notifications';
import Account from './Account/Account';
import NavigationBar from './NavigationBar/NavigationBar';
import 'ui-neumorphism/dist/index.css';
import './App.css';
import { Card } from 'ui-neumorphism';
import {Route, BrowserRouter, Switch } from 'react-router-dom';

function App() {
  const [dark_mode, setMode] = useState(false);
  return (
    <div className="App">
      <BrowserRouter>
      <Card rounded width={300} height={600} dark = {dark_mode} className='main-card'>
          <Switch>
            <Route path="/PlanList">
              <PlanList dark = {dark_mode}/>
            </Route>
            <Route path="/Food">
              <Food dark = {dark_mode}/>
            </Route>
            <Route path="/Notification">
              <Notifications dark = {dark_mode}/>
            </Route>
            <Route path="/Account">
              <Account dark = {dark_mode} setMode = {setMode}/>
            </Route>
            <Route path="/">
              <Program dark = {dark_mode}/>
            </Route>
          </Switch>
          <NavigationBar dark_mode = {dark_mode}/>
      </Card>
      </BrowserRouter>
    </div>
  );
}

export default App;

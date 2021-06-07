import React, { useState } from 'react';
import Program from './Program/Program';
import PlanList from './PlanList/PlanList';
import Food from './Food/Food';
import Notifications from './Notification/Notifications';
import Account from './Account/Account';
import NavigationBar from './NavigationBar/NavigationBar';
import 'ui-neumorphism/dist/index.css';
import './App.css';
import { Card, Switch } from 'ui-neumorphism';
import { Route, Router } from 'react-router';
import { Link } from 'react-router-dom';

function App() {
  const [dark_mode, setMode] = useState(false);
  const [page = 'Program', setPage] = useState('Program');
  return (
    <div className="App">
        <Router>
          {/* <div>
            <nav>
              <ul>
                <li>
                  <Link to = "/Program">Program</Link>
                </li>
                <li>
                  <Link to = "/PlanList">PlanList</Link>
                </li>
                <li>
                  <Link to = "/Food">Food</Link>
                </li>
                <li>
                  <Link to = "/Notification">Notification</Link>
                </li>
                <li>
                  <Link to = "/Account">Account</Link>
                </li>
              </ul>
            </nav>
          </div> */}
          <Card rounded width={300} height={600} dark = {dark_mode} className='main-card'>
            <Switch>
              <Route path = "/">
                <Program dark = {dark_mode}/>
              </Route>
              <Route path = "/PlanList">
                <PlanList dark = {dark_mode}/>
              </Route>
              <Route path = "/Food">
                <Food dark = {dark_mode}/>
              </Route>
              <Route path = "/Notification">
                <Notifications dark = {dark_mode}/>
              </Route>
              <Route path = "/Account">
                <Account dark = {dark_mode} setMode = {setMode}/>
              </Route>
            </Switch>
            <NavigationBar 
              dark_mode = {dark_mode}
              page = {page}
              setPage = {setPage}
              setMode = {setMode}
            />
          </Card>
        </Router>
    </div>
  );
}

{/* <Program dark = {dark_mode}/>
<PlanList dark = {dark_mode}/>
<Food dark = {dark_mode}/>
<Notifications dark = {dark_mode}/> */}
{/* <Account dark = {dark_mode} dark_mode = {dark_mode} setMode = {setMode}/> */}
export default App;

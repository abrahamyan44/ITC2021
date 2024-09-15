import 'ui-neumorphism/dist/index.css';
import {
  BrowserRouter,
  Switch,
  Route
} from "react-router-dom";

import Program from './Program/Program';
import PlanList from './PlanList/PlanList';
import Food from './Food/Food';
import Notification from './Notification/Notification';
import Profile from './Profile/Profile';
import './App.css';

const routes = [
  {
    path: '/',
    component: Program
  },
  {
    path: '/program',
    component: Program
  },
  {
    path: '/planlist',
    component: PlanList
  },
  {
    path: '/food',
    component: Food
  },
  {
    path: '/notification',
    component: Notification
  },
  {
    path: '/profile',
    component: Profile
  }
];

function App() {

  return (
    <>
    <BrowserRouter>
      <Switch>
        {routes.map((route, index) =>
          <Route key={index} exact path={route.path} component={route.component} />
        )}
      </Switch>
    </BrowserRouter>
    </>
  );
}

export default App;

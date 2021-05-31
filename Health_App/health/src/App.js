import "./App.css";

import React from "react";

import {
  CardContent,
  Subtitle2,
  H5,
  Body2,
  Card,

} from "ui-neumorphism";
import 'ui-neumorphism/dist/index.css';

import TrainingCard from './component/TrainingCard/TrainingCard.jsx';


function App() {
  return (
    <div className="App">
      <Card width={300} height={600}>
        <CardContent>
        <Subtitle2 secondary style={{ marginBottom: '4px' }} >
          Word of the day
        </Subtitle2>
        <TrainingCard></TrainingCard>
      </CardContent>
      </Card>
    </div>
  );
}

export default App;

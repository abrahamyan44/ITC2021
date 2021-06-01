import "./pages.css"
import React from "react";

import {
  CardContent,
  Subtitle2,
  H5,
  Body2,
  Card,

} from "ui-neumorphism";
import 'ui-neumorphism/dist/index.css';
import {
    mdiRun,
    mdiArmFlex,
    mdiYoga
} from '@mdi/js';

import TrainingCard from '../component/TrainingCard/TrainingCard.jsx';
import './Home.css';


function Home() {
  return (
    <div className="Page">
      <Card width={350} height={600}>
        <CardContent>
        <H5 secondary style={{ marginBottom: '4px' }} >
          Word of the day
        </H5>
        <div className='cardContainer'>
            <TrainingCard icon={mdiRun} title='Run'></TrainingCard>
            <TrainingCard icon={mdiArmFlex} title='Arm'></TrainingCard>
            <TrainingCard icon={mdiYoga} title='Yoga'></TrainingCard>
        </div>

      </CardContent>
      </Card>
    </div>
  );
}

export default Home;
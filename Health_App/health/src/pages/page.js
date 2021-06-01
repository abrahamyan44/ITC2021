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

import TrainingCard from '../component/TrainingCard/TrainingCard.jsx';


function Home(props) {
    return (
    <div className="Page">
      <Card width={350} height={600}>
        <CardContent>
        <H5 secondary style={{ marginBottom: '4px' }} >
          {props.title}
        </H5>
        <TrainingCard></TrainingCard>
      </CardContent>
      </Card>
    </div>
  );
}

export default Home;
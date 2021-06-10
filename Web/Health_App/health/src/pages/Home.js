import "./Home.css"
import React from "react";

import {
  CardContent,
  H3,
  H5,
  Card,
  IconButton,
  Body2
} from "ui-neumorphism";
import 'ui-neumorphism/dist/index.css';
import {
    mdiRun,
    mdiArmFlex,
    mdiYoga,
    mdiDumbbell,
    mdiStarBox,
    mdiMenuRight
} from '@mdi/js';
import Icon from '@mdi/react';

import TrainingCard from '../component/TrainingCard/TrainingCard.jsx';

function Home() {
  return (
    <div className="Page">
      <Card width={350} height={600} elevation={5}>
        <CardContent>
        <H3 secondary style={{ marginBottom: '4px' }} >
          Program
        </H3>
        <div className='cardContainer'>
            <TrainingCard icon={mdiRun} title='Run' fettle='In progress...'></TrainingCard>
            <TrainingCard icon={mdiArmFlex} title='Arm' fettle='In progress...'></TrainingCard>
            <TrainingCard icon={mdiYoga} title='Yoga' fettle='No task'></TrainingCard>
            <TrainingCard icon={mdiDumbbell} title='Weight' fettle='Have finished'></TrainingCard>
        </div>
        <H5>
            Courses Collection
        </H5>
        <div>
          <Card width={300} height={80}>
          <div className='cardContainer'>
                <Card outlined width={40} height={30}>
                  <IconButton className='ma-12' size='small'>
                    <Icon path={mdiStarBox} size={0.8} />
                  </IconButton>
                </Card>
                <Card elevation={0} width={180} height={60}>
                  <Body2>
                    <br/>
                    Courses I attended <br></br>
                  </Body2>
                  <Body2 secondary>
                    11 courses in total 
                  </Body2>
                </Card>
                <Card elevation={5} border-radius={50}>
                <IconButton className='ma-12' size='small'>
                <Icon path={mdiMenuRight} size={0.8} />
        </IconButton>
                </Card>
            </div>
          </Card> 
        </div>


      </CardContent>
      </Card>
    </div>
  );
}

export default Home;
import "./TrainingCard.css";

import React from "react";
import {
    CardContent,
    H5,
    Body2,
    Card,
    IconButton
} from "ui-neumorphism";

import Icon from '@mdi/react';



function TrainingCard(props) {
  return (
    <span className="App">
      <Card width={150} height={150}>
        <CardContent>
        <IconButton className='ma-12' size='small'>
                <Icon path={props.icon} size={0.8} />
        </IconButton>
        <H5>
          {props.title}<br></br>
          Training
        </H5>
        <Body2 secondary>
            In progres...
        </Body2>
      </CardContent>
      </Card>
    </span>
  );
}

export default TrainingCard;

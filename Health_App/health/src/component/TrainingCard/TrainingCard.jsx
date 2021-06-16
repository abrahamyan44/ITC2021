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
import {
    mdiRun
} from '@mdi/js';


function TrainingCard() {
  return (
    <div className="App">
      <Card width={150} height={150}>
        <CardContent>
        <IconButton className='ma-12' size='small'>
                <Icon path={mdiRun} size={0.8} />
        </IconButton>
        <H5>
          Run<br></br>
          Training
        </H5>
        <Body2 secondary>
            In progres...
        </Body2>
      </CardContent>
      </Card>
    </div>
  );
}

export default TrainingCard;

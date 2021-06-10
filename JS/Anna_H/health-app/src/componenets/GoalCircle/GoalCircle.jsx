import React from 'react';
import { Card, CardContent, H5, Subtitle1 } from 'ui-neumorphism';
import Icon from '@mdi/react';
import {
    mdiRun
} from '@mdi/js';
import './GoalCircle.css';


function GoalCircle(props) {
    return (
        <Card className="goal-container" height={200} width={200}>
            <CardContent className="goal-subcontainer" >
                    <Icon path={mdiRun}  color='var(--primary)' size={3} style={{height: '4rem', padding: '4px'}}/>
                <H5>
                    8,690
                </H5>
                <Subtitle1 secondary>
                    Goal: 12k
                </Subtitle1>
            </CardContent> 
        </Card>
    )
}

export default GoalCircle;
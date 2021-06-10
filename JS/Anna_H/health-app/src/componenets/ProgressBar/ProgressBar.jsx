import React from 'react';
import { Card, CardContent, ProgressCircular, Subtitle1, Subtitle2 } from 'ui-neumorphism';
import Icon from '@mdi/react';
import './ProgressBar.css';


function ProgressBar(props) {
    return (
        <Card className="progressbar-container" height={85} width={300}>
            <CardContent height={85} className="progressbar-subcontainer" > 
                <Icon path={props.icon} color='var(--primary)' size={1.8} style={{padding: '4px'}}/>
               <div> 
                <Subtitle1>
                    {`Complited: ${props.title} group`}
                </Subtitle1>
                <Subtitle2>
                    {`Goal: ${props.text} group`}
                </Subtitle2>
                </div>
                <ProgressCircular value={props.value} color='var(--primary)'>{`${props.value}%`}</ProgressCircular>
            </CardContent> 
        </Card>
    )
}

export default ProgressBar;
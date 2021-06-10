import React from 'react';
import { Card, CardContent, IconButton, Subtitle1, Subtitle2, Fab } from 'ui-neumorphism';
import Icon from '@mdi/react';
import {
    mdiTicket
} from '@mdi/js';
import './CourseInfoBar.css';


function CourseInfoBar(props) {
    return (
        <Card className="bar" height={85} width={300}>
            <CardContent height={85} className="courses-bar" > 
                <IconButton size='large' color='var(--primary)' bordered={true} >
                    <Icon path={mdiTicket} size={2} style={{padding: '4px'}}/>
                </IconButton>
                <div> 
                <Subtitle1>
                    Course I attend
                </Subtitle1>
                <Subtitle2 secondary>
                    11 courses in total
                </Subtitle2>
                </div>
                <Fab size='small'>
                    <span style={{ fontSize: '15px', color: 'var(--primary)'}}>&#62;</span>
                </Fab>
            </CardContent>
        </Card>
    )
}

export default CourseInfoBar;
import React from 'react';
import { Card, CardContent, H4, Fab } from 'ui-neumorphism';
import Navigation from '../componenets/Navigation/Navigation.jsx';
import GoalCircle from '../componenets/GoalCircle/GoalCircle';
import ProgressBar from '../componenets/ProgressBar/ProgressBar';
import {
    mdiArmFlex, mdiDumbbell
} from '@mdi/js';
import './PlanList.css'

const progressArray = [
    {
        icon: mdiArmFlex,
        title: 3,
        text: 4,
        value: 75
    },
    {
        icon: mdiDumbbell,
        title: 6,
        text: 6,
        value: 100
    }
]

function PlanList(props) {
    return (
        <>
            <Card rounded width={340} height={610} className='card'>
                <CardContent className='planlist-container'>
                    <div className="planlist-header">
                        <H4 className='planlist-card-title'>Plan list</H4>
                        <Fab className="plus-icon" size='small'>
                            <span style={{ fontSize: '25px', color: 'var(--primary)'}}>&#43;</span>
                        </Fab>
                    </div>
                    <GoalCircle />
                    {progressArray.map((el) => {
                        return <ProgressBar icon={el.icon} title={el.title} text={el.text} value={el.value} />
                    })}
                </CardContent>
                <Navigation />
            </Card>
        </>
    )
}

export default PlanList;
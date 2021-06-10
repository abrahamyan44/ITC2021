import React from 'react';
import {Card, CardContent,  H4, H6} from 'ui-neumorphism';
import Training from '../componenets/Training/Training.jsx'
import Navigation from '../componenets/Navigation/Navigation.jsx';
import './Program.css'
import CourseInfoBar from '../componenets/CourseInfoBar/CourseInfoBar.jsx';
import {
    mdiArmFlex, mdiDumbbell, mdiRun, mdiYoga
} from '@mdi/js';

const trainingArray = [
    {
        icon: mdiArmFlex,
        title: 'Arm',
        text: 'in progress...'
    },
    {
        icon: mdiDumbbell,
        title: 'Weight',
        text: 'Have finished'
    },
    {
        icon: mdiRun,
        title: 'Run',
        text: 'in progress...'
    },
    {
        icon: mdiYoga,
        title: 'Yoga',
        text: 'No task'
    }
]

function Program(props) {
    return(
        <>
            <Card rounded width={340} height={610} className='card'>
                <CardContent className='program-card-content'>
                    <H4 className='program-card-title'>Program</H4>
                    <div className='cardContainer'>
                        {trainingArray.map((el) => { 
                            return <Training icon={el.icon} title={el.title} text={el.text}/>})}
                    </div>
                    <H6 className='collections'>
                        Courses Collections
                    </H6>
                    <CourseInfoBar/>
                </CardContent>
                <Navigation />
            </Card>
        </>
    )
} 

export default Program;
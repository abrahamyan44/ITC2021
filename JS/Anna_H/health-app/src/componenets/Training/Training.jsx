import React from 'react';
import Icon from '@mdi/react'
import {Card, CardContent, Subtitle1, Body2} from 'ui-neumorphism';
import './Training.css'


function Training(props) {
    return(
        <>
            <Card rounded width={135} height={150} className='training-bar'>
                <CardContent>
                    <Icon path={props.icon} color='var(--primary)' size={1.2}/>
                    <Subtitle1 style={{ marginBottom: '4px' }} >
                        {props.title}<br></br>
                        Training
                    </Subtitle1>
                    <Body2 secondary>
                        {props.text}
                    </Body2>
                </CardContent>
            </Card>
        </>
    )
}

export default Training;
import React from 'react';
import './TrainingCard.css'
import Icon from '@mdi/react';
import {
    Subtitle2,
    Caption,
    Card
} from 'ui-neumorphism';

class Training extends React.Component {
    render() {
        const {dark, icon, title, subtitle, progress} = this.props;
        return (
            <Card elevation={2} dark={dark} className='card'>
                <Card flat className="icon">
                    <Icon path={icon} size={1.3} color='var(--primary)'></Icon>
                </Card>
                <Subtitle2 className='subtitle0'>{title}</Subtitle2>
                <Subtitle2 className='subtitle1'>{subtitle}</Subtitle2>
                <Caption secondary className='progress'>{progress}</Caption>
            </Card>
        )
    }
}

export default Training;
